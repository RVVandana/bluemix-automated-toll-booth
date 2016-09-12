# BLUEMIX AUTOMATED TOLL BOOTH
Smart Toll Plaza System using RFID is an enhancement to the currently deployed manual toll collection system. Time and efficiency are a matter of priority in present days. To over come the major problem of traffic congestion at toll plaza during peak hours , this RF Id based smart toll collection system makes toll transaction more convenient for travellers. Considering the present toll collection system , where all vehicles have to stop and pay taxes. On an average each vehicle passing through a toll plaza has to wait approx. 2 minute in a toll at engine start condition which thereby aids in air pollution and wastage of fuel &amp; money. If this system comes to existence, the waiting time at toll plaza will be reduced.  In this project, an RF Id card in the vehicle will be scanned by the reader placed at the toll plaza to automate the toll collection and billing for the user. This system also supports a mobile app for notifying the user about the toll transaction. Further, this app can also assist the user to check their historical toll transactions, &amp; manage money recharge. This system has a unique feature whereby the system can report a stolen vehicle if the vehicle’s owner blocks it.

#DEVICE BUILD

Step 1: Setting up the IDE to Program the Linkit ONE

Installing the Arduino Linkit ONE Core with the Boards Manager

Download and Install Arduino 1.6.6 from [https://www.arduino.cc/en/Main/Software]
Start Arduino and open Preferences window.
Enter http://download.labs.mediatek.com/package_mtk_linkit_index.json into Additional Board Manager URLs field.
You can add multiple URLs, separating them with commas.
Open Boards Manager from Tools > Boards > Board menu and install.

#Uploading the Program to the LINKIT ONE using the Arduino IDE

Step 1: Get this Git Repo to your desktop using,

https://github.com/suryasundarraj/bluemix-automated-toll-booth.git

Step 2: Open the codes in Arduino IDE

Step 3: Select Linkit One from the Device List

Step 4: Select the USB Port from Tools - > Linkit Debug Port

Step 5: Edit the SSID and PASSWORD to configure to your router

Step 6: Edit the pubnub publish and subscribe keys to your unique key provided by pubnub.com(if required)

Step 7: Upload the Code to the Linkit ONE

#MOBILE APP BUILD

Steps to be followed to Build and Run the Android App for Automated System (Note : Assumed Cordova framework installed in your system) (For pre-compiled app follow Step 4) Step 1 : Change the cordova project directory

    cd (folder_name)
Step 2 : Modify the pubnub publish and subscribe keys at www/js/index.js

Step 3 : Build the .apk file using,

    cordova build android
Step 4 : Once the .apk file is build successfully, you will find the app at this path

    ./platforms/android/build/output/android-debug.apk
Step 5 : Install the APP on an Android Phone.
