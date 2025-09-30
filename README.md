# Hardware-In-The-Loop approach for fault simulation and validation of diagnostic modules in Unmanned Aerial Vehicles

!logo_faultInjection_Matlab.png

Questo repository contiene il codice e i modelli sviluppati per la **diagnosi dei guasti negli UAV (Unmanned Aerial Vehicles)** mediante tecniche di **Machine Learning**. Il progetto prevede l'implementazione e l'analisi di moduli diagnostici sia su un **calcolatore di bordo** (simulazione) che su un **flight controller reale (Pixhawk)**.

## Caratteristiche principali
- **Simulazione MATLAB & Simulink** per testare gli algoritmi diagnostici prima dell'implementazione reale.
- **Implementazione di moduli di Fault Injection** per la simulazione di guasti nei sensori e attuatori.
- **Modelli di Machine Learning** per rilevare guasti nei sensori e negli attuatori degli UAV.
- **Integrazione su Flight Controller (Pixhawk)** con ottimizzazione per dispositivi embedded.
- **Analisi delle prestazioni** con confronto tra esecuzione su calcolatore e su hardware reale.

## Struttura del repository
- **ClassificationLearner/**:
Contiene i risultati ottenuti tramite Classification Learner per l’addestramento dei modelli di classificazione dei guasti, utilizzati nella diagnosi.
- **DFD/**:
Include gli output del Diagnostic Feature Designer, relativi all’estrazione delle feature dai dati grezzi.
- **ETL/**:
Script e file utilizzati nella fase di Extract, Transform, Load (ETL) dei dataset.
- **FlightVisualPX4HITLUAV/**:
Firmware PX4 per il sistema UAV HITL (Hardware-In-The-Loop).
- **TreeModel/**:
Modello di classificazione ad albero basato su dati PX4.
- **mission_plan/**:
File di missione per il software QGroundControl, utilizzati per la pianificazione dei voli.
- **Simulazione Guasti.mlx**:
Script MATLAB contenente il modello matematico per la simulazione dei guasti.
- **tesi_cardoni_lorenzo.pdf**:
Documento della tesi di progetto.
- **logo_faultInjection_Matlab.png**:
Logo del progetto, relativo al toolbox di iniezione guasti in MATLAB.
- **plot3xyz.m**:
Script MATLAB per la visualizzazione 3D della traiettoria di volo.
- **plot_fault.m**:
Script MATLAB per la visualizzazione dei guasti rilevati.



## Requisiti
### Software:
- **MATLAB & Simulink** (con toolbox per UAV, Diagnostic feature Designer e Classification Learner)
- **PX4 Firmware** (per l'implementazione sul flight controller)
- **QGroundControl** (per test e configurazione della Pixhawk)

### Hardware:
- **Pixhawk** con firmware PX4
- **Computer per la simulazione MATLAB & Simulink**

## Istruzioni per l'uso
###  Installazione dei requisiti
### 1️. Simulazione su MATLAB & Simulink

### 2️. Implementazione su Pixhawk

### Risultati e Analisi
I risultati dell'implementazione e della validazione del modulo di Fault Injection sono disponibili nel file *Tesi_Cardoni_Lorenzo.pdf*.

### Possibili sviluppi futuri
- Miglioramento degli algoritmi di Machine Learning per una maggiore accuratezza diagnostica.
- Integrazione con tecniche di Deep Learning per una rilevazione più avanzata.
- Ottimizzazione delle prestazioni su hardware embedded per ridurre il carico computazionale.
- Test su scenari di volo reali con UAV fisici.

### 👨‍💻 Autore
Lorenzo Cardoni – cardonilorenzo31@gmail.com
