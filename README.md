# 🛸 Diagnosi Guasti per UAV con Machine Learning

Questo repository contiene il codice e i modelli sviluppati per la **diagnosi dei guasti negli UAV (Unmanned Aerial Vehicles)** mediante tecniche di **Machine Learning**. Il progetto prevede l'implementazione e l'analisi di moduli diagnostici sia su un **calcolatore di bordo** (simulazione) che su un **flight controller reale (Pixhawk)**.

## 📌 Caratteristiche principali
- **Simulazione MATLAB & Simulink** per testare gli algoritmi diagnostici prima dell'implementazione reale.
- **Implementazione di moduli di Fault Injection** per la simulazione di guasti nei sensori e attuatori.
- **Modelli di Machine Learning** per rilevare guasti nei sensori e negli attuatori degli UAV.
- **Integrazione su Flight Controller (Pixhawk)** con ottimizzazione per dispositivi embedded.
- **Analisi delle prestazioni** con confronto tra esecuzione su calcolatore e su hardware reale.

## 🛠️ Struttura del repository



## 🚀 Requisiti
### Software:
- **MATLAB & Simulink** (con toolbox per UAV, Diagnostic feature Designer e Classification Learner)
- **PX4 Firmware** (per l'implementazione sul flight controller)
- **QGroundControl** (per test e configurazione della Pixhawk)

### Hardware:
- **Pixhawk** con firmware PX4
- **Computer per la simulazione MATLAB & Simulink**

## 📖 Istruzioni per l'uso
###  Installazione dei requisiti
### 1️⃣ Simulazione su MATLAB & Simulink
Aprire il file simulink/diagnosi_uav.slx in MATLAB e avviare la simulazione.

### 2️⃣ Implementazione su Pixhawk
Compilare e caricare il firmware modificato in firmware/ sulla Pixhawk.
Collegare il flight controller a QGroundControl per la configurazione.
Avviare i test in volo monitorando i risultati diagnostici.
### 📊 Risultati e Analisi
I risultati dell'implementazione e della validazione del modulo di Fault Injection sono disponibili nel file *Tesi_Cardoni_Lorenzo.pdf*.

### 🔥 Possibili sviluppi futuri
Miglioramento degli algoritmi di Machine Learning per una maggiore accuratezza diagnostica.
Integrazione con tecniche di Deep Learning per una rilevazione più avanzata.
Ottimizzazione delle prestazioni su hardware embedded per ridurre il carico computazionale.
Test su scenari di volo reali con UAV fisici.
### 👨‍💻 Autore
Lorenzo Cardoni – cardonilorenzo31@gmail.com
