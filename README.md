# Thermometer

[![](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/xRealNeon/Thermometer/blob/master/LICENSE)
[![Discord](https://discordapp.com/api/guilds/365206523749728266/embed.png)](https://discord.gg/rpvdY42)

## Features
- Mobile web app compatible
- API
- FlatUI dashboard
- Config generator

## Use the API
### Get the temperature: `GET` yoururl/json?k=yourkey

#### Response
| Name          | Type          | Example     |
| ------------- |:-------------:|-------------|
| in            | float         | 22.45       |
| out           | float         | 15.32       |

## Hardware
- [NodeMcu (Ebay)](https://www.ebay.com/itm/NodeMcu-Lua-WIFI-Internet-Things-development-board-based-ESP8266-CP2102-module/201542946669)
- [NodeMcu (AliExpress)](https://www.aliexpress.com/item/New-Wireless-module-NodeMcu-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266-with-pcb-Antenna/32656775273.html)
- [DS18B20 (Ebay)](https://www.ebay.com/itm/10-20-50PCS-DS18B20-9-12bit-Temperature-Sensor-Dallas-Thermometer-Sensor-TO-92/192733327656)
- [DS18B20 (AliExpress)](https://www.aliexpress.com/item/freeshipping-new-and-original-DS18B20-Digital-Thermometer-Sensor/1049373066.html)
- [DS18B20 Outdoor (Ebay)](https://www.ebay.com/itm/10pcs-Waterproof-DS18B20-Digital-Thermal-Probe-SensorTemperature-Sensor-100cm-TS/113336693808)
- [DS18B20 Outdoor (AliExpress)](https://www.aliexpress.com/item/Free-Shipping-1PCS-Digital-Temperature-Temp-Sensor-Probe-DS18B20-For-Thermometer-1m-Waterproof-100CM/32522322459.html)

## Libraries used
- [Bootstrap](https://getbootstrap.com/)
- [MobileDetect](https://hgoebl.github.io/mobile-detect.js/)
- [Odometer](https://github.hubspot.com/odometer/)
- OneWire
- DallasTemperature
