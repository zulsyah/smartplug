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
5 | 128x64 OLED Screen | 1 | https://shopee.com.my/product/33091591/2353226119
6 | USB Charger 3A | 1 | https://shopee.com.my/Four-USB-Port-3-Pin-Plug-UK-Mains-Wall-Charger-Adaptor-Samsung-Apple-Tablet-FAST-CHARGING-CHARGER-i.237476310.6737584818
7 | Project Box 8x6 inch | 1 | https://shopee.com.my/PVC-Multipurpose-Waterproof-Weatherproof-Electronic-Project-Enclosure-Box-(-8x6-8x6XH-10X8-10X8-XH-12X9X6)-i.47940013.5800748480
8 | Voltage Sensor Module | 2 | https://shopee.com.my/product/132528683/2883120650
9 | DHT11 Temperature and Humidity Sensor Module | 1 | https://shopee.com.my/product/132528683/2011544803
10 | MB102 830 Holes Large Solderless Breadboard | 1 | https://shopee.com.my/product/132528683/2006168670

## Senarai perpustakaan yang digunakan

Spi | Wire | Adafruit_GFX | Adafruit_SH110X | WiFiClient
----- | ----- | ----- | ----- | ----- |
**TinyGsmClient** | **BlynkSimpleTinyGSM** | **ACS712** | **WiFi** | **BlynkSimpleEsp32**

__________________________________________________________________________________________________________________
