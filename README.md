# twitch_water_gun
A water gun linked to twitch channel points (can be modified to be used with a chat command)

# Summary
 - Prerequesites
 - Technical explanation
 - Installation
    - Nodered flow
    - ESP32 (arduino) code
 - Credit

# Prerequesites
  - A nodered server (free low code GUI for NodeJS server) https://nodered.org/
  - An ESP32 (nano computer that is supporting WiFi, Bluetooth, Arduino language). There is lot of models with ESP32 CPU, I m personally using this one : https://fr.aliexpress.com/item/33043305592.html
  - A 5V 1A electric supply with micro male USB exit
  - A 5V electric relay : https://www.amazon.fr/gp/product/B07CNR7K9B/ref=ppx_yo_dt_b_asin_title_o08_s00?ie=UTF8&psc=1
  - All need to do solder on basic PCB (soldering iron, tin, basic electric cable
  - A water pump for little aquarium : https://www.amazon.fr/gp/product/B082PM8L6X/ref=ppx_yo_dt_b_asin_title_o07_s00?ie=UTF8&psc=1

# Technical explanation
The objective is to activate the water-pump when viewers using a specific channel reward.
  - The viewer activate the channel reward
  - The nodered server receive the chat message with reward ID
  - The nodered server sent a HTTP request to the ESP32
  - The ESP32 activate the relay for 0.5 second
  - The relay closing the alimentation circuit of the water-pump
  - The water pump is very simple and just need an alimentation to run, so it's running and you are watered

# Credit
Create by tainalo2 : french streamer on twitch every week day from 07H to 09H (Paris hours)
All my links here : https://linktr.ee/tainalo2
