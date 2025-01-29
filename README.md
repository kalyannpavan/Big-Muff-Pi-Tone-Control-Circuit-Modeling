# 🎸 Digital Audio Plugin for Big Muff Pi Tone Control Circuit | JUCE, HISE  

---

## 🎚️ Big Muff Pi Tone Control Circuit  

<p align="center">
  <img src="![image](https://github.com/user-attachments/assets/50ad43d8-4a45-4001-bc94-2436106537f7)
">
</p>  

---

## 🚀 Overview  
This project involves designing and **digitally replicating** the **Big Muff Pi Tone Control Circuit**, a key component of the famous Big Muff Pi distortion pedal. The focus of this project is to analyze the **passive tone control circuit**, simulate its behavior, and create a digital audio plugin that accurately mimics its performance. The workflow includes:  

✅ **Analog circuit simulation** using **TINA**  
✅ **Frequency response analysis** and **MNA** for transfer functions  
✅ **Digital transformation** using **OCTAVE scripts**  
✅ **Plugin development** using **JUCE & HISE**

---

## 🔥 Key Features  

### 🎛️ Analog Circuit Simulation  
✔ Designed and simulated the **Big Muff Pi’s Passive Tone Control** in **TINA**, analyzing the transfer function and waveform characteristics.  

### 📐 Frequency Response Analysis  
✔ Analyzed the frequency response, showcasing:  
   - **7dB overall attenuation**  
   - **6.5dB dip at 1KHz**, with variations based on **treble** and **bass** settings.  

### 🧑‍🏫 Theoretical Insights & MNA  
✔ Used **Modified Nodal Analysis (MNA)** to derive transfer functions for accurate circuit behavior modeling.  

### 🎛️ Digital Transformation  
✔ Converted the analog model to **digital using OCTAVE scripts**, ensuring faithful replication of the analog characteristics.  

### 🎵 Plugin Development  
✔ Developed a **JUCE/C++ audio plugin** and integrated it into the **HISE platform** to allow musicians to use the tone control functionality in real-time.  

---

## ⚙️ Workflow  

### 🛠️ **Step 1: Analog Circuit Simulation**  
- Designed and simulated the **Big Muff Pi Tone Control** in **TINA**, analyzing the **transfer function** and **waveform characteristics**.  
- Focused on the use of a **100K potentiometer** to create a **1KHz notch** in the frequency response.  

### 📊 **Step 2: Frequency Response Analysis**  
- Analyzed the frequency response:  
   - **7dB overall attenuation**  
   - A **6.5dB dip at 1KHz**, with treble and bass variations.  

### 🧑‍🏫 **Step 3: Theoretical Insights & MNA**  
- Applied **Modified Nodal Analysis (MNA)** to derive the **transfer function**, simplifying the circuit for further analysis.  

### 💻 **Step 4: Digital Conversion**  
- Converted the analog model into **OCTAVE scripts**, simulating its digital audio response.  
- Ensured that the digital model accurately replicated the analog frequency response characteristics.  

### 🔧 **Step 5: Plugin Development**  
- Developed a **JUCE/C++ audio plugin**, designed to work seamlessly in digital audio workstations (DAWs).  
- Integrated the plugin into the **HISE platform**, allowing real-time use by musicians and sound engineers.  

---

## 🏆 Results  

✔ **Achieved a 7dB overall attenuation** with a **6.5dB dip at 1KHz**, mimicking the original Big Muff Pi circuit.  
✔ **Successfully converted** the analog circuit model into a **digital audio plugin** for real-time performance.  
✔ **Delivered a functional plugin** that enhances usability for **musicians and audio engineers**, replicating the iconic tone control of the Big Muff Pi.  

---

## 🛠️ Tools & Technologies  

| Tool | Purpose |
|------|---------|
| 🎛️ **TINA** | Analog circuit modeling & simulation |
| 📊 **OCTAVE** | Digital transformation & script validation |
| 🎵 **JUCE (C++)** | Plugin development framework |
| 🎚 **HISE Platform** | Audio plugin integration & testing |

---

## 📸 Screenshots & Visuals  

### 📟 **Circuit Schematic**  
<p align="center">
  <img src="![image](https://github.com/user-attachments/assets/694f78bd-f71d-43de-a20e-4fa7e268649d)
">
</p>  

---

### 📊 **Frequency Response Plot (OCTAVE)**  
<p align="center">
  <img src="![image](https://github.com/user-attachments/assets/220f29af-e19c-4b83-921a-3a95790fa104)
">
</p>  

<p align="center">
  <img src="![image](https://github.com/user-attachments/assets/8916620b-e419-4f38-88f8-19518d19953f)
">
</p> 

<p align="center">
  <img src="![image](https://github.com/user-attachments/assets/d13bb797-d0b2-48c2-af8a-bab428d807f2)

">
</p> 

---


