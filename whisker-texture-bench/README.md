# Actuated Whisker Texture-Classification Bench

**Status:** Built | **Year:** 2026
**Stack:** ESP32, Python, pyqtgraph, scikit-learn, 1D-CNN

ESP32/Arduino bench where a servo/voice-coil actuator sweeps two whisker designs (uniform vs graded stiffness) over textured samples at several frequencies. MEMS microphone (I2S) and piezo at the whisker base, own driver stage. Synchronised Python acquisition with a live pyqtgraph dashboard; FFT/MFCC features into SVM, random forest and 1D-CNN classifiers, comparing designs and actuation frequencies.

Personal project, not employer or customer work.

*Code, photos and results: added as they are cleaned up.*

