# 📡 VBan-ESP32Mic 🎤

Transformez votre ESP32 en une passerelle audio connectée grâce à la capture du son d'un micro I2S et la transmission VBAN !

## 🚀 Fonctionnalités

- **🎙 Capture Audio** : Support des microphones I2S (PDM) avec des configurations ajustables (Testé sur M5 Stack Atom Echo)
- **🌐 Transmission VBAN** : Diffusion en réseau local via le protocole VBAN
- **📶 Connectivité Wi-Fi** : Intégration facile au réseau sans fil

## 🛠️ Matériel et Pré-requis

### Matériel requis
- ESP32
- Microphone I2S compatible (M5 Stack Atom Echo recommandé)
- Réseau Wi-Fi

### Bibliothèques nécessaires
- Installez la bibliothèque `AudioTools` depuis [AudioTools GitHub Repository](https://github.com/pschatzmann/arduino-audio-tools) :
  1. Allez dans **Sketch > Include library > Add .ZIP Library ...**
  2. Selectionnez le fichier ZIP

### Pinout sur M5 Stack Atom Echo
- `pin_ws` : GPIO 33
- `pin_data` : GPIO 23

## ⚙️ Instructions d'Installation

1. Clonez ce repository :
   ```bash
   git clone https://github.com/lfpoulain/vban-esp32mic.git
   ```

2. Ouvrez le fichier `.ino` dans l'IDE Arduino

3. Assurez-vous que la bibliothèque `AudioTools` est correctement installée

4. Configurez vos paramètres Wi-Fi dans le fichier comme suit :
   ```cpp
   cfg_vban.ssid = "VotreSSID";
   cfg_vban.password = "VotreMotDePasse";
   cfg_vban.stream_name = "Esp32Mic"; 
   ```

5. Connectez votre ESP32 à votre ordinateur via USB

6. Sélectionnez la carte ESP32 et le port COM correspondant dans l'IDE Arduino :
   - **Outils > Type de carte > ESP32 > Modèle ESP32 utilisé** (ex. ESP32 Dev Module)
   - **Outils > Port** : Choisissez le port COM correspondant à votre ESP32

7. Téléversez le code

## 🧪 Test et Utilisation

Une fois téléversé, l'ESP32 démarrera automatiquement :
- Capturera le son du microphone I2S connecté
- Transmettra le flux audio via le protocole VBAN

Assurez-vous que le réseau VBAN est actif pour recevoir les données (par exemple, via VBAN Receptor ou Voicemeeter).

## 🛡️ Licence

Ce projet est sous licence MIT. Faites-en bon usage ! 😄

**🎉 Amusez-vous bien avec votre projet ESP32 et VBAN !**
