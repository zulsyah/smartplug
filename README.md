# Smart Plug v1.0
Smart plug using TTGO T-Call ESP32 with GSM Module

- AZ Putra (zulsyah7@gmail.com)
- Hafiz Ismail (a165174@siswa.ukm.edu.my)
- Din Concodei (din@din.com)

# Bahasa Melayu #

Assalamualaikum, syukur ke hadrat ilahi kerana dengan kurniaNya saya dapat menghasilkan projek ini. Projek ini masih tidak siap sepenuhnya tapi saya berpuas hati dengan apa yang saya dapat capai.

## Fungsi projek ini

1. Mengawal soket elektrik secara individu 
2. Mengira penggunaan elektrik bagi setiap soket atau keseluruhan soket
3. Merekod semua data penggunaan elektrik ke pangkalan data (MySQL) --todo
4. Mengira kadar caj elektrik berdasarkan tariff TNB Malaysia --todo
5. Merekod kadar caj elektrik ke pangkalan data (MySQL) --todo

## Pengenalan projek

Laman Github ini mengandungi kod sumber Arduino (source code) bagi modul TTGO T-Call ESP32 SIM800L. Format fail tersebut adalah (.ino).

Projek ini mempunyai dua mod konektiviti iaitu sama ada menggunakan WiFi atau GSM (EDGE/GPRS). Oleh itu, modul TTGO T-Call ESP32 SIM800L ini dilengkapkan dengan slot kad sim.

Jika anda ingin menggunakan kad sim sebagai konektiviti Intenet, anda boleh memasukkan kad sim anda (pastikan anda mempunyai pelan data Internet yang masih aktif) ke dalam modul tersebut. Jika tidak, anda boleh terus mengikut tutorial di bawah.

### Cara penggunaan sistem ini (WiFi)

1. Buka fail `TTGO_WIFI_ESP32_ACS712_CurrentSensor.ino` menggunakan Arduino IDE
2. Muat turun aplikasi Blynk dari Google Play Store pada telefon anda
3. Daftarkan ESP32 Devkit anda dan dapatkan token Blynk anda menggunakan aplikasi tersebut
4. Pastikan anda memilih WiFi sebagai 'Connection Type'
5. Ubah nama dan katalaluan WiFi anda serta token Blynk yang anda perolehi tadi

```java
//Token Blynk anda
char auth[] = "Your Blynk Auth";

//Nama dan kataluan WiFi anda
char ssid[] = "Your SSID";
char pass[] = "Your WiFi password";
```
5. Simpan dan muat naik kod tersebut ke TTGO T-Call ESP32 SIM800L
6. Buka 'Serial Monitor' dan lihat data tersebut (Arus dan Volt) dipancarkan.

### Cara penggunaan sistem ini (GSM)

1. Buka fail `TTGO_GSM_ESP32_ACS712_CurrentSensor.ino` menggunakan Arduino IDE
2. Muat turun aplikasi Blynk dari Google Play Store pada telefon anda
3. Daftarkan ESP32 Devkit anda dan dapatkan token Blynk anda menggunakan aplikasi tersebut
4. Pastikan anda memilih GSM sebagai 'Connection Type'
5. Ubah apn mengikut kesesuaian Telco anda serta token Blynk yang anda perolehi tadi

```java
//Token Blynk anda
char auth[] = "Your Blynk Auth";

//APN Telco and (abaikan user/pass) *isi jika perlu
char apn[] = "Your Telco APN";
char user[] = "";
char pass[] = "";
```
5. Simpan dan muat naik kod tersebut ke TTGO T-Call ESP32 SIM800L
6. Buka 'Serial Monitor' dan lihat data tersebut (Arus dan Volt) dipancarkan.

## Antara muka dalam aplikasi Blynk

Aplikasi ini hanya mempunyai satu antara muka sahaja.
<p align="centre"> <img src="https://i.imgur.com/dnVdc89.jpg" width="25%" height="25%"> </p>

## Senarai modul / sensor yang digunakan

Bil | Nama modul | Kuantiti | Pautan pembelian
------------- | ------------- | ------------- | ------------- |
1 | TTGO T-Call ESP32 SIM800L | 1 | https://shopee.com.my/-SKL-TTGO-T-Call-V1.3-ESP32-Wireless-Module-USB-to-TTL-CP2104-WiFi-BT-UART-I2C-I2S-i.270000701.7958966270
2 | 4-channel relays 5v | 1 | https://shopee.com.my/Arduino-IoT-4-Channel-Ways-Opto-Isolator-10A-5V-Relay-Module-i.33091591.733102947
3 | ACS712 20A Current Sensor | 2 | https://shopee.com.my/ACS712-Arduino-Current-Sensor-Module-5A-20A-30A-i.23949362.858209494
4 | ZMPT101B AC Voltage Sensor | 1 | https://shopee.com.my/AC-Voltage-Sensor-Module-ZMPT101B-(Single-Phase)-i.40459773.6806793152
5 | Mini DC-DC 4.5-24V to 5V 3A Step Down | 1 | https://shopee.com.my/product/33091591/2353226119
6 | ADS1115 16-bit Analog to Digital Converter | 1 | https://shopee.com.my/product/132528683/6917873642
7 | PCF8574T I2C IIC Extension Board | 2 | https://shopee.com.my/product/132528683/5931423335
8 | Voltage Sensor Module | 2 | https://shopee.com.my/product/132528683/2883120650
9 | DHT11 Temperature and Humidity Sensor Module | 1 | https://shopee.com.my/product/132528683/2011544803
10 | MB102 830 Holes Large Solderless Breadboard | 1 | https://shopee.com.my/product/132528683/2006168670

## Senarai perpustakaan yang digunakan

Spi | Wire | Adafruit_GFX | Adafruit_SH110X
----- | ----- | ----- | ----- |
**TinyGsmClient** | **BlynkSimpleTinyGSM** | **ACS712** | **WiFi**

__________________________________________________________________________________________________________________

# English #

To download the code, please download file named 'ESP8266_SmartCar.ino'

### List of sensors and modules that used in this project

No | Modules name | Quantity | Purchase links
------------- | ------------- | ------------- | ------------- |
1 | NodeMCU v2 ESP8266 Board | 1 | https://shopee.com.my/Arduino-NODEMCU-Lua-IoT-I2C-ESP8266-Wifi-Controller-Board-ESP-12-V2-i.33091591.480433851
2 | 8-channel relays 12v | 1 | https://shopee.com.my/Arduino-IoT-8-Channel-Way-Opto-Isolator-5V-Relay-Module-i.33091591.1027038464
3 | 4-channel relays 5v | 1 | https://shopee.com.my/Arduino-IoT-4-Channel-Ways-Opto-Isolator-10A-5V-Relay-Module-i.33091591.733102947
4 | GY-NEO6MV2 GPS Module | 1 | https://shopee.com.my/Arduino-GY-NEO6MV2-GPS-Track-Location-Tracking-Flight-Control-GPS-Module-with-Antenna-MWC-AMP2.5-i.33091591.943603180
5 | Mini DC-DC 4.5-24V to 5V 3A Step Down | 1 | https://shopee.com.my/product/33091591/2353226119
6 | ADS1115 16-bit Analog to Digital Converter | 1 | https://shopee.com.my/product/132528683/6917873642
7 | PCF8574T I2C IIC Extension Board | 2 | https://shopee.com.my/product/132528683/5931423335
8 | Voltage Sensor Module | 2 | https://shopee.com.my/product/132528683/2883120650
9 | DHT11 Temperature and Humidity Sensor Module | 1 | https://shopee.com.my/product/132528683/2011544803
10 | MB102 830 Holes Large Solderless Breadboard | 1 | https://shopee.com.my/product/132528683/2006168670

### List of libraries used

BlynkSimpleEsp8266 | ESP8266WiFi | dht11 | SoftwareSerial
----- | ----- | ----- | ----- |
**TinyGPS++** | **Arduino** | **PCF8574** | **Adafruit_ADS1015**
