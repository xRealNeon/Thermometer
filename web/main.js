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

function init() {
    console.log("Thermometer v" + version + " by NeoCode");
    console.log("checking for updates...");
    client.get('https://raw.githubusercontent.com/xRealNeon/Thermometer/master/version', function (response) {
        if (version == response) {
            console.log("no updates found!");
        } else {
            console.log("update found to version " + response);
            alert("update found to version " + response);
        }
        console.log("reloading in 30 seconds");
    });

    client.get(ip + '/json?k=' + key, function (response) {
        var root = JSON.parse(response);
        upg.innerHTML = root.in;
        downg.innerHTML = root.out;
    });

    setInterval(function () {
        console.log("reloading!");
        client.get(ip + '/json?k=' + key, function (response) {
            var root = JSON.parse(response);
            upg.innerHTML = root.in;
            downg.innerHTML = root.out;
        });
    }, 30000);
}
