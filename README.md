# TP2
Trabajo Práctico Nro2 Curso ARM-Book
## Nombre: Santiago Nolasco 
## email: santiagonolasco86@gmail.com

# Medidor de concentración de alcohol en el aire (Alcoholímetro)
## Descripción:
El sistema es un medidor de alcohol, esto lo toma a través de un sensor conectado a la entrada analógica (A1). Esta medición la realiza en todo momento y es mostrada a traves de un display 16x2 comunicado con la placa NÚCLEO F429Z por I2C.
La transmición de los datos sólo se realizará cuando se oprima el pulsador (BUTTON1), los datos se mostraran cada medio segundo.
La implementación de maquina de estados se realizo con el único púlsador del sistema (BUTTON1).
# Vistas
<img src="https://github.com/SNolasco86/TP1/blob/main/placa_1.jpeg" width="425" height="495">
<img src="https://github.com/SNolasco86/TP1/blob/main/placa_2.jpeg" width="425" height="495">

# Consideraciones de la Placa

 - **Entradas digitales:** BUTTON1 conectadas pullup.
 - **Entrada analógica:** A1 conectada al potenciómetro (simulando un sensor de alcohol mq-3).
 - **Salidas digitales I2C:** Display LCD 16x2.
 - **Conexión serie:** Conexión usb-serial

# Materiales

 - **NUCLEO F429ZI
 - **Cable usb
 - **Potenciómetro
 - **Pulsador NA
 - **Cables macho-macho varios
 - **Display LCD 16x2
