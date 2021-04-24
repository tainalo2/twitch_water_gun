# twitch_water_gun
A water gun linked to twitch channel points (can be modified to be used with a chat command)

# Summary
 - Prerequesites
 - Technical explanation
 - Installation
    - Twitch
    - ESP32 (arduino) code
    - Nodered flow
    - Physical set up with electric cables
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

# Installation
 - Twitch
    - Create a channel point reward, the only needed is to activate the "Ask viewer to enter text" option !
 
 - ESP32 (arduino) code
    - First you need to have an Arduino IDE modified to support ESP32 televersing, I invite you to follow this tutorial : https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
    - Import the "ESP32_arduino_waterGun.ino" file or copy/paste it your IDE
    - On line 10 and 11 replace "Your_SSID" and "Your_WiFi_password" by your local WiFi parameters
    - Click on "Tools" and look at what you have in "Port" (don't forget !)
    - Link your ESP32 to your PC with a classic USB to micro USB cable with data pin
    - Return to "Tools">"Port" and select the one how just appeared
    - Click on the arrow icon and wait the console say it's finished
    - Go in "Tools" > "Serie monitor" and reset the ESP32 by clicking the physic button
    - In the monitor find the IP assigned to your ESP32 and save it
    - To be sure to keep this IP I'm advising you setup a fix DHCP lease to the ESP32

 - Nodered flow
    - First you need to have a Nodered server, I invite you to follow the official tutorial : https://nodered.org/docs/getting-started/
    - On your Nodered interface, go to "Manage palette">"Install" option, search and install the librarie called : "node-red-contrib-twitch-chat"
    - On your Nodered interface, go to "Import" option and copy/paste the content of file "Nodered_flow_waterGun.json" and click "Import"
    - In the flow that have been create enter the "Incoming message" node (with double click)
    - Over the line "Config" click on the pencil
    - In "Config Name" add you want it's only the name of the configuration (no technical impact)
    - In "username" and "password" write a twitch account login/password that wil be used to interact with the channel chat
    - In "channels" list of chat channels you want to scan (I m putting only mine)
    - Click "Update"
    - Click "Done"
    - Click "Deploy"
    - Go in the "Debug" menu by clicking on the bug icon (under the "Deploy" button)
    - Go in your chat twitch and use the reward you have create like a viewer
    - In Nodered on your "Debug" menu you have a message like "f188178f-5fed-4db6-9ef8-20d05b6b7252" it's the reward ID : copy it
    - Go in the node "switch" and replace "your_reward_ID" by the reward ID
    - Click "Done"
    - Go in the node "http request" and replace "YOUR_ESP32_IP" by the IP of your ESP32 that you have save
    - Click "Done"
    - Click "Deploy"

 - Physical set up with electric cables
    - Get the phisical_schema.png and reproduce it with electric cable
    - I'm advising you to not screw the cable between relay and water pump to do first test
    - To test, switch on the ESP32, use your channel point reward and listen to the relay, if it works you will hear a sound like a big mouse click
    - Once done screw last cables
    - Put some tube on the water pump
    - Let the pump in water (I'm using a glass of water) (don't activate pump out of water, it could broke the motor)
    - I'm putting a clothespin over the tube to create some pressure, without it water don't do any distance...
    - Have a good stream !

# Credit
Create by tainalo2 : french streamer on twitch every week day from 07H to 09H (Paris hours)
All my links here : https://linktr.ee/tainalo2
