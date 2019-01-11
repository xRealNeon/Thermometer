var HttpClient = function () {
    this.get = function (aUrl, aCallback) {
        var anHttpRequest = new XMLHttpRequest();
        anHttpRequest.onreadystatechange = function () {
            if (anHttpRequest.readyState == 4 && anHttpRequest.status == 200)
                aCallback(anHttpRequest.responseText);
        }
        anHttpRequest.open("GET", aUrl, true);
        anHttpRequest.send(null);
    }
}
var client = new HttpClient();
var config;
var mainfile;

function init() {
    client.get('https://raw.githubusercontent.com/xRealNeon/Thermometer/master/arduino/Thermometer/Config.h', function (response) {
        config = response;
    });
    client.get('https://raw.githubusercontent.com/xRealNeon/Thermometer/master/arduino/Thermometer/Thermometer.ino', function (response) {
        mainfile = response;
    });
    console.log();
}
var gkey;

function press() {
    config = config.replace('const char* ssid = "";', 'const char* ssid = "' + document.getElementById("wlanssid").value + '";');
    config = config.replace('const char* password = "";', 'const char* password = "' + document.getElementById("wlanpass").value + '";');
    if (document.getElementById("key").value !== "") {
        gkey = document.getElementById("key").value;
        config = config.replace('const String key = "";', 'const String key = "' + gkey + '";');
    } else {
        gkey = getRandom();
        config = config.replace('const String key = "";', 'const String key = "' + gkey + '";');
    }
    var url = document.getElementById("url").value;
    if (url.endsWith("/")) {
        url = url.slice(0, -1);
    }
    config = config.replace('const String url = "";', 'const String url = "' + url + '";');
    if (document.getElementById("statusled").value !== "") {
        config = config.replace('const int statusled = LED_BUILTIN;', 'const char* statusled = ' + document.getElementById("statusled").value + ';');
    }
    config = config.replace('const char* outpin = D1;', 'const char* outpin = ' + document.getElementById("outpin").value + ';');
    config = config.replace('const char* inpin = D2;', 'const char* inpin = ' + document.getElementById("inpin").value + ';');
    var zip = new JSZip();
    var folder = zip.folder("Thermometer");
    folder.file("Config.h", config);
    folder.file("Thermometer.ino", mainfile);
    zip.generateAsync({
            type: "blob"
        })
        .then(function (content) {
            saveAs(content, "Thermometer.zip");
            $('#donemodal').modal('show');
        });
}

function openT() {
    var win = window.open(document.getElementById("url").value + "?k=" + gkey, '_blank');
    win.focus();
}

function getRandom() {
    return Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5) + Math.random().toString(36).slice(-5);
}
