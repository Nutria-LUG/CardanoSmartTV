# Questo programma utilizza un file di configurazione per
# attribuire una string a un comando. Prende in input un
# comando vocale e se si trova nel dizionario di
# configurazione, esegue il comando associato.

import config
import subprocess
import sys

#Questo si trova dentro la libreria pyaudio
import speech_recognition as sr


# Questa funzione si mette in ascolto di un comando vocale
# e ritorna il comando detto come stringa.
def get_command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Wait ...")
        # we only need to calibrate once, before we start listening
        r.adjust_for_ambient_noise(source)

        print("Say something!")
        audio = r.listen(source)
    command = None
    
    # recognize speech using Sphinx
    try:
        print("Sphinx thinks you said " + r.recognize_sphinx(audio))
    except sr.UnknownValueError:
        print("Sphinx could not understand audio")
    except sr.RequestError as e:
        print("Sphinx error; {0}".format(e))

    
    try:
        command = r.recognize_google(audio)
        print("You Said " +  command)
    except sr.UnknownValueError:
        print("I don't understand, repeat please")
        get_command()
    except sr.RequestError as e:
        print("Could not request results from Google Speech " +
              "Recognition service; {0}".format(e))

    return command 


command = get_command()

if command in config.commands:
    subprocess.call(config.commands[command])
else:
    print 'Nope'


# import os
# from pocketsphinx import LiveSpeech, get_model_path

# model_path = "/home/gabriele/cardano/CardanoSmartTV/pyscripts/it-models/etc/"
# print(model_path)
# speech = LiveSpeech(
#     verbose=False,
#     sampling_rate=16000,
#     buffer_size=2048,
#     no_search=False,
#     full_utt=False,
#     hmm=os.path.join(model_path, 'voxforge_it_sphinx.filler'),
#     lm=os.path.join(model_path, 'voxforge_it_sphinx.lm'),
#     dic=os.path.join(model_path, 'voxforge_it_sphinx.dic')
# )

# for phrase in speech:
#     print(phrase)
