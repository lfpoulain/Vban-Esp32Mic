/**
 * Ce programme utilise un ESP32 pour :
 * 1. Capturer l'audio depuis un microphone I2S/PDM
 * 2. Transmettre le flux audio via VBAN sur le réseau WiFi
 */

// Inclusion des bibliothèques nécessaires
#include "AudioTools.h"
#include "AudioTools/AudioLibs/VBANStream.h"

// Déclaration des objets pour la gestion des flux audio
I2SStream i2sStream;    // Gère l'entrée audio I2S
VBANStream vbanStream;  // Gère la sortie audio VBAN
StreamCopy copier(vbanStream, i2sStream);  // Copie les données entre les flux

void setup() {
  // Initialisation de la communication série pour le débogage
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);

  // Configuration du flux I2S (entrée audio)
  Serial.println("Starting I2S...");
  auto cfg_i2s = i2sStream.defaultConfig(RX_MODE);
  cfg_i2s.bits_per_sample = 16;    // Résolution audio 16 bits
  cfg_i2s.channels = 1;            // Mode mono
  cfg_i2s.sample_rate = 16000;     // Fréquence d'échantillonnage 16kHz
  cfg_i2s.signal_type = PDM;       // Type de signal : PDM (Pulse Density Modulation)
  cfg_i2s.use_apll = false;        // Désactive l'APLL pour l'horloge
  cfg_i2s.auto_clear = false;      // Désactive le nettoyage automatique du buffer
  cfg_i2s.pin_ws = 33;            // Pin Word Select (WS) sur GPIO33
  cfg_i2s.pin_data = 23;          // Pin Data sur GPIO23
  i2sStream.begin(cfg_i2s);

  // Configuration du flux VBAN (sortie réseau)
  Serial.println("Starting VBAN...");
  auto cfg_vban = vbanStream.defaultConfig(TX_MODE);
  cfg_vban.ssid = "VotreSSID";           // SSID du réseau WiFi
  cfg_vban.password = "VotreMotDePasse";  // Mot de passe WiFi
  cfg_vban.stream_name = "Esp32Mic";      // Nom du flux VBAN
  // Configuration VBAN identique à I2S pour assurer la compatibilité
  cfg_vban.channels = cfg_i2s.channels;
  cfg_vban.sample_rate = cfg_i2s.sample_rate;
  cfg_vban.bits_per_sample = cfg_i2s.bits_per_sample;
  vbanStream.begin(cfg_vban);

  Serial.println("Setup completed");
}

void loop() {
  // Copie continue des données audio de I2S vers VBAN
  copier.copy();
}