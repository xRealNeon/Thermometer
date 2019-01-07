# Thermometer

[![](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/xRealNeon/Thermometer/blob/master/LICENSE)
[![Discord](https://discordapp.com/api/guilds/365206523749728266/embed.png)](https://discord.gg/rpvdY42)

## Features
- Mobile web app compatible
- API
- FlatUI dashboard

## Use the API
### Get the temperature: `GET` yoururl/json?k=yourkey

#### Response
| Name          | Type          |
| ------------- |:-------------:|
| in            | float         |
| out           | float         |

## Hardware
- [ESP8266](https://www.ebay.com/itm/NodeMcu-Lua-WIFI-Internet-Things-development-board-based-ESP8266-CP2102-module/201542946669)
- [DS18B20](https://www.ebay.com/itm/10pcs-Waterproof-DS18B20-Digital-Thermal-Probe-SensorTemperature-Sensor-100cm-TS/113336693808)

## Libraries used
- [Odometer](https://github.hubspot.com/odometer/)
- OneWire
- DallasTemperature
