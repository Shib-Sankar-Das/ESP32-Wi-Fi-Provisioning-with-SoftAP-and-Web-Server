# ESP32 Wi-Fi Provisioning with SoftAP & Web Server

This project enables **Wi-Fi provisioning** on an **ESP32** using **SoftAP mode** and a **web server**. Users can connect to the ESP32's access point, enter Wi-Fi credentials via a web page, and establish a connection to their home network.

![Picsart_25-04-01_06-10-36-034](https://github.com/user-attachments/assets/2bcd1eb5-fbf2-4b0a-9e0d-a3fdd810dedf)

---

## **📌 Use Case: Why Use This System?**  

### **1️⃣ Simplified Wi-Fi Provisioning for ESP32 ⚡**  
   - ✅ Enables seamless connection of ESP32 to Wi-Fi **without hardcoding credentials**.  
   - 🖥️ Users can configure Wi-Fi via a **web interface** instead of modifying firmware.  

### **2️⃣ Secure and User-Friendly Connectivity 🔒**  
   - 📡 ESP32 acts as an **Access Point (AP)** for easy initial setup.  
   - 🔐 Credentials are transmitted **securely** through a local web server.  

### **3️⃣ Real-Time Hardware Control via Web 🌐**  
   - ⚙️ Allows **real-time interaction** between the ESP32 and a web-based dashboard.  
   - 📲 Hardware can be **controlled or monitored remotely** without exposing sensitive data.  

### **4️⃣ Dynamic 3D Model Control 🎮**  
   - 🖱️ Users can **manipulate 3D models** using ESP32 with gyroscope/accelerometer sensors.  
   - 🚀 Real-time **movement synchronization** enhances interactive applications.  

### **5️⃣ Global Accessibility with Secure Authentication 🌍**  
   - 🔑 **Hardware authentication** ensures only authorized devices can interact.  
   - ☁️ Supports **cloud integration** while maintaining **data privacy & security**.  

---

## 🚀 Features
- Creates a **SoftAP** (ESP32_Provisioning) for Wi-Fi setup.
- Hosts a **web interface** for entering Wi-Fi credentials.
- Saves credentials and **automatically connects** to Wi-Fi.
- Displays connection **status via HTTP endpoint**.
- Uses **LittleFS** for hosting the web page.

---

## 🛠️ Hardware Requirements
- ESP32 Development Board
- USB Cable
- Computer with Arduino IDE or PlatformIO

---

## 📂 Folder Structure
```
wifi_provisioning/
├── data/                         # Contains web files (index.html)
│   ├── index.html                # Web interface for Wi-Fi provisioning
├── wifi_provisioning.ino         # Main ESP32 firmware
```

---

## 🔧 Installation & Setup
### 1️⃣ Install ESP32 Board in Arduino IDE
Follow [this guide](https://github.com/espressif/arduino-esp32) to install ESP32 support in Arduino IDE.

### 2️⃣ Install Required Libraries
Make sure you have these libraries installed:
- **ESPAsyncWebServer** ([GitHub](https://github.com/me-no-dev/ESPAsyncWebServer))
- **AsyncTCP** ([GitHub](https://github.com/me-no-dev/AsyncTCP))
- **LittleFS** ([GitHub](https://github.com/espressif/arduino-esp32/tree/master/libraries/LittleFS))

### 3️⃣ Upload Web Files to LittleFS
Use the **ESP32 LittleFS Data Upload Tool** to upload `index.html` to LittleFS.

### 4️⃣ Flash the ESP32
Upload the `wifi_provisioning.ino` file using **Arduino IDE** or **PlatformIO**.

---

## 🖥️ How It Works
1. ESP32 starts in **SoftAP mode** (default SSID: `ESP32_Provisioning`).
2. User connects to the ESP32's Wi-Fi and accesses `http://192.168.4.1/`.
3. User enters Wi-Fi credentials and submits the form.
4. ESP32 attempts to connect to the provided Wi-Fi network.
5. If successful, ESP32 runs as a normal Wi-Fi client.
6. The connection status is available at `http://ESP_IP/status`.

---

## 📜 API Endpoints
| Endpoint         | Method | Description |
|-----------------|--------|-------------|
| `/`             | GET    | Serves the Wi-Fi setup page |
| `/connect`      | POST   | Accepts `ssid` & `password` and connects to Wi-Fi |
| `/status`       | GET    | Shows the current connection status |

---

## 🛠️ Troubleshooting
- **ESP32 does not create SoftAP?**
  - Make sure you have flashed the correct firmware.
  - Check the Serial Monitor for error logs.

- **Web page is not loading?**
  - Ensure `index.html` is uploaded to **LittleFS**.
  - Try clearing browser cache or using an incognito window.

- **ESP32 fails to connect to Wi-Fi?**
  - Check if the credentials are correct.
  - Try moving the ESP32 closer to the router.

---

## 📜 License
This project is licensed under the **MIT License**.

---

## 🌟 Contributing
Pull requests are welcome! If you find a bug or have a feature request, feel free to **open an issue**.

---

