# Smart Highway Toll Collection System using IBM Bluemix and Mediatek LinkItONE

This is the project repository for Smart Highway Toll Collection System. Refer to the sections below for configuration, build and deployment instructions. 

This is the accompanying project for this blog post.

# Components

The project has following components

## Hardware setup for toll booth
Refer the hardware setup and schematic in the blog post.

The BOM for Hardware components is 

1. Mediatek Linkit ONE Board (1 no.)

2. RFID Reader Module - EM 18  (1 no.)

3. Servo Motor - V3006 (1 no.)

4. Smart RFID Passive Tag , 125 kHz (1 no.)

## Backend Server Setup

The backend server for this project is hosted on IBM Bluemix. PubNub is also used for messaging purposes between the server and hardware and app. You will need to sign up for Bluemix and PubNub subscription.

## Mobile App
User mobile app for managing individual toll transactions. The app is based on Apache Cordova 


#Device Build

Follow these instructions to build the toll booth device software for LinkitONE. 

## Prerequisites: Arduino IDE 

Setting up the Arduino IDE to Program the Linkit ONE

Installing the Arduino Linkit ONE Core with the Boards Manager

Download and Install Arduino 1.6.6 from [https://www.arduino.cc/en/Main/Software]
Start Arduino and open Preferences window.
Enter http://download.labs.mediatek.com/package_mtk_linkit_index.json into Additional Board Manager URLs field.
You can add multiple URLs, separating them with commas.
Open Boards Manager from Tools > Boards > Board menu and install.

## Uploading the Program to the LINKIT ONE using the Arduino IDE

Step 1: Get this Git Repo to your desktop using,

https://github.com/shyampurk/bluemix-automated-toll-booth.git

Step 2: Open the source code under [rfidLinkit](/rfidLinkit) in Arduino IDE

Step 3: Select Linkit One from the Device List

Step 4: Select the USB Port from Tools - > Linkit Debug Port

Step 5: In [settings.h](rfidLinkit/settings.h), line 9,10 and 11, edit the SSID and PASSWORD to configure to your router

Step 6: [settings.h](rfidLinkit/settings.h), in line 14 & 15, edit the pubnub publish and subscribe keys as per your unique key provided by pubnub.com

Step 7: Upload the Code to the Linkit ONE

# Mobile App Build

Steps to be followed to Build and Run the Android App for Automated Toll System (Note : Assuming Cordova framework installed in your system) (For pre-compiled app follow Step 4) 

Step 1 : Change to the Cordova project directory
    
    cd android app/autotoll/

Step 2 : Modify the pubnub publish and subscribe keys at www/js/index.js (Line 77, 78)

Step 3 : Build the .apk file using the command

    cordova build android
    
Step 4 : Once the .apk file is build successfully, you will find the app at this path

    ./platforms/android/build/output/android-debug.apk
    
Step 5 : Install the APP on an Android Phone.

## Mobile App Registration

(This step should be performed only after the server application is deployed in Bluemix. Refer the steps below for Bluemix deployment)

After installing the mobile app, launch it on your mobile. On the starting screen of the app, you will be asked to enter the vehicle registration number. Enter the same vehicle registration number that you provisioned in the DashDB database as part of vehicle data loading.
	
	Enter the registered vehicle number and click Login.
	Your name, vehicle type and the wallet balance info will be displayed on the App.


# Bluemix Deployment

Steps for deploying the application server on Bluemix.

## Prerequisites

    -   You should have a valid IBM account.
    -   You should have a Bluemix subscription and access to your Bluemix dashboard with atleast one space created.
    -   You should have the Cloudfoundry command line tool installed.
            (https://github.com/cloudfoundry/cli/releases)
    -   You should have a PubNub subscription


## DashDB  Configuration

Before we run the server application, we need to create a DashDB instance.

Step 1: Login to Bluemix with your credentials.

Step 2: In your dashboard, goto Catalog and select the Data and Analytics Section.

You can see that the dashDB service  listed under this section or you can search for dashDB

Step 3: Click on dashDB service icon and create a dashDB service instance for your space by filling following details,
      
        1) Connect to   - You can select "leave unbound"
        2) Service name - Enter a name for the service of your choice
        3) Credential name - Enter a name for the Credential of your choice
        4) Selected Plan - Choose 'Entry'.
        5) Click CREATE to create the dashdb service instance.

Step 4: After creation of the service, go back to dashboard.Now you can see the dashDB service added to your space. Click the service and click the launch button and you can see your newly created dashDB service home page.

Step 5: In the dashDB service home page, under the Side Menu, under the Connect -> Connection information,
	    You can see your dashDB Host name,Database name,user id and password.

	    Make a note of Host Name, Port Number , Database Name, User ID and Password.

Step 6: In the Side Main Menu, click on "Run SQL" and you will be presented the Run SQL screen. Click on the 'Upload' button and choose the SQL schema file (db.sql link)
Click on the ‘Run All’ button to execute the SQL statements.

Step 7: If the Run command executed successfully, you will be able to see the new tables created under your dashDB instance
Click on “Tables” submenu. Select the table from “Table Name ” dropdown to access the table schema and data. You can find two tables listed under the dropdown 
        
        VEHICLE_INFO
        TOLL_DATA

### Loading Vehicle Data in DashDB

Step 1 : Get the RFID number

Follow these steps to get teh RFID number of the tag.

	1.	Make the hardware setup as per the schematic give in the blog post.
	
	2.	Upload the test_app/rfidTagReader/rfidTagReader.ino file to the Linkit One through the Linkit Port [Tools->Port->LinkitOne], under Arduino IDE.
	
	3. 	Open the serial monitor, and start swiping the cards across the RFID Reader.
	
	4. 	The RFID number will be printed on the serial monitor.
	
	5. 	Make a note the RFID number and make sure to use that number in the dataabse for provisioning vehicle data.
	
Step 2 : Once you got the RFID number open the userData.sql(link for that) and modify it by following the instructions as follows.
		
		In the sql file you can see the SQL query like
		INSERT INTO VEHICLE_INFO VALUES ('JOHN','KA0H1234','CAR',100,0,'090096B43E15');

		Here the column data is mapped as follows 
			John is the USER_NAME : Vehicle owner name
			KA0H1234 is VEHICLE_NUMBER : Your Vehicle registration number (Remember you have to enter the same when you are starting your mobile app)
			CAR is VEHICLE_TYPE : Type of vehicle
			100 is WALLET_BAL  : Amount in your account
			0 is BLOCK_STATUS : Vechicle blocked status (initial it is zero which indiates not blocked)
			090096B43E15 is RFID : RFID Tag number (that you got in the first step)

		Modify the INSERT data as per your wish ensuring that the RFID tag is correctl. You can also make multiple INSERT entries if you have more RFID tags. Save the file after all modifications.

Step 3 : In the Side Main Menu, click on "Run SQL" and you will be presented the Run SQL screen. Click on the 'Upload' button and 			choose the SQL schema file (userData.sql link) which you just modified in the previous step.

Step 4 : Click on the ‘Run All’ button to execute the SQL statements.
 		If the Run command executed successfully , you will be able to see the inserted values in the VEHICLE_INFO Table.

## Deploying the Toll Management Server Application in Bluemix

Step 1 - Update the parameters in the [config.ini](toll_server/config.ini) file

	pub_key = PubNub publish key
	sub_key = PubNub subscribe key
	db_schema =   UserID of the DashDB instance , in caps
	db_host = Host Name
	username = User ID of the DashDB instance
	pwd = Password of dashDB instance
	port = Port Number  
	table_name = Table name is set to VEHICLE_INFO
	table_name = Table name is set to TOLL_DATA

Step 2 - Open the [manifest file](toll_server/manifest.yml) and update the following entries
	
	applications:
        		- name : <name of the application on server>

    	services
        		- <dashdb instance name>

   	 where 
        		<name of the application on server> - Any desired name for the application
        		<dashdb instance name> - name of the dashdb service instance that you have created in the previous section.

Step 3 - Login to Bluemix console via cf tool and select the space.

Step 4 - Change directory to the server application root (toll_server) under the cloned GitHub repository.

Step 5 - Run the following command to push the application code to bluemix
	‘cf push’

Once successfully pushed, the server application will be automatically started. You can check its state in your Bluemix dashboard and see that its state is set to 'Running'.


