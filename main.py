import speech_recognition as sr
import serial
import time

# 1. CONEXÃO ARDUINO
try:
    arduino = serial.Serial('COM8', 9600)
    time.sleep(2)
    print("Conectado ao Arduino com sucesso!")
except Exception as e:
    print(f"Erro de conexão: {e}")
    exit()

rec = sr.Recognizer()

def ouvir_e_comandar():
    with sr.Microphone() as mic:
        rec.adjust_for_ambient_noise(mic, duration=1)
        print("\n>>> Aguardando comando (fale algo ao jarvis)...")
        
        try:
            audio = rec.listen(mic, timeout=5, phrase_time_limit=3)
            texto = rec.recognize_google(audio, language="pt-BR").lower()
            print(f"Você disse: {texto}")

            if "abrir"  in texto:
                arduino.write(b'A')
                print("--- Comando ENVIADO: abrindo a mão ---")
            elif "um dedo" in texto:
                arduino.write(b'U')
                print("--- Comando ENVIADO: fechando 1 ---")
            elif "dois dedos" in texto:
                arduino.write(b'D')
                print("--- Comando ENVIADO: fechando 2 ---")
            elif "três dedos" in texto:
                arduino.write(b'T')
                print("--- Comando ENVIADO: fechando 3 ---")
            elif "primeiro dedo" in texto:
                arduino.write(b'P')
                print("--- Comando ENVIADO: fechando primeiro ---")
            elif "segundo dedo" in texto:
                arduino.write(b'S')
                print("--- Comando ENVIADO: fechando segundo ---")
            elif "terceiro dedo" in texto:
                arduino.write(b'E')
                print("--- Comando ENVIADO: fechando terceiro ---")
            elif "quarto dedo" in texto:
                arduino.write(b'Q')
                print("--- Comando ENVIADO: fechando quarto ---")
            elif "fechar" in texto:
                arduino.write(b'F')
                print("--- Comando ENVIADO: fechando a mão ---")
            elif "vamos grêmio" in texto:
                arduino.write(b'G')
                print("--- Comando ENVIADO: fechando a mão ---")
            elif "desligar" in texto:
                print("--- Parando ---")
                arduino.write(b'A')
                arduino.close() # Fecha a conexão com o Arduino antes de sair
                exit()
            
        except sr.UnknownValueError:
            print("Não entendi o que você disse.")
        except sr.WaitTimeoutError:
            pass 
        except Exception as e:
            print(f"Erro no processamento: {e}")

while True:
    ouvir_e_comandar()