
# Hosting a Website using Flask

In this tutorial, we will use Flask with Python 3 on an Amazon Linux 2 EC2 instance.

**Terminologies**
In this document, the term
 - **Virtual Machine** refers to the EC2 instance running on Amazon Web Services with Amazon Linux 2 operating system
 - **Terminal** or **Shell** or **Console** refers to the SSH connection established with the *virtual machine* through one of the following software 
 -- *Termius* (Windows, Mac, Linux, Android, iOS) **(Recommended)**
 -- *Terminal* (Mac, Linux)
 -- *Putty* or *Command Prompt* (Windows)

I have used *Termius* while writing this tutorial.

| **What is Web Framework?** | **What is Flask?** |
|--|--|
| Web Application Framework or simply Web Framework represents a collection of libraries and modules that enables a web application developer to write applications without having to bother about low-level details such as protocols, thread management etc. | Flask is a web application framework written in Python. It is developed by  **Armin Ronacher**, who leads an international group of Python enthusiasts named Pocco. Flask is based on the Werkzeug WSGI toolkit and Jinja2 template engine. Both are Pocco projects. |

### Table of Contents
1. [Setting up the Environment](#settingup)
	
	-- [Installing Python 3](#installpython3)
	
	-- [Installing Flask](#installflask)
	
	-- [Understanding Processes](#processes)
	
	-- [Netstat](#netstat)
	
	-- [cURL](#curl)
	
2. [First Program](#firstprogram)
3. [Making the Web Server available over Internet](#publicweb)

<a name="settingup"></a>
## Setting up the Environment
<a name="installpython3"></a>
### Installing Python 3

Check if your *virtual machine* has Python 3 installed. You can do so by executing the following command in your *virtual machine's* terminal

    python3 -V

If your *virtual machine* has Python 3 installed, the terminal should respond you with the version of Python 3 installed

    Python 3.X.Y

If you got the above response, feel free to [skip the following and move to the Installing Flask section](#installflask)

else the response will be

    -bash: python3: command not found

Run the following command to install python 3 on your *virtual machine*'s terminal

    sudo yum install python3 -y

This should install Python 3 and the dependencies in your *virtual machine*. Make sure you see the message **Complete!** to confirm the installation.

<a name="installflask"></a>
### Installing Flask

Unlike the installation of Python 3, the installation of Flask works differently. This is because, Python 3 is a software package for the operating system and Flask is a library for Python.

To install Flask for Python 3, execute the following command in the Terminal

    sudo pip3 install flask
<a name="processes"></a>
### Understanding Processes

In Linux operating system (or in fact any OS), when a software or a program starts, a process gets initialised and keeps running until it is quit.

To list the processes running in the *virtual machine*, you can execute the following command

    ps

This will list all the processes running for the current user. However, there could be a number of other processes running in the *virtual machine* initialised by other users

The list usually prints the following

|	PID 		|	TTY		|	TIME			|	CMD	|
|	:----:	|	:----:	|	:----:			|	:----	|
|	1250	|	pts/0	|	00:00:00	|	bash	|
|	2356	|	pts/0	|	00:00:00	|	ps	|

PID is the Process ID, unique to each process

To quit / kill a process, the following command can be used

    kill -9 PID
<a name="netstat"></a>
### Netstat

Netstat (Network Statistics) is a command line network utility which can be used to monitor the *virtual machine*'s network connections (input and output communication), routine tables, network interfaces and so on.

You can learn more about this utility by executing the following command

    netstat --help

Our interest in this utility is to monitor the open TCP ports due to services hosted by this *virtual machine*. This can be achieved by executing the following command

    netstat -ltn4
This command lists the services that are listening for TCP based communication from IPv4 clients and resolving the names of these services into corresponding port numbers

An example of this is as follows

Proto	|	Recv-Q	|	Send-Q	|	Local Address	|	Foreign Address	|	State      
:----| :----:| :----:| :----:| :----:| :----:
tcp	| 0 | 0 | 0.0.0.0:22 | 0.0.0.0:* | LISTEN

> The number 22 in Local Address field signifies that the *virtual machine* is listening to clients trying to communicate to a service hosted on port 22 (SSH)
> 
> And the address 0.0.0.0 signifies that the service hosted on port 22 is available for any client with an IPv4 address (if they have the right credentials to access the service)

When we host a Webserver using Flask, we should be able to see a new service hosted on port 5000 here (by default Flask hosts a web server on port 5000)
<a name="curl"></a>
### cURL

cURL is a command-line tool for getting or sending data including files using [URL](https://en.wikipedia.org/wiki/URL "URL") syntax

In this tutorial, we will make use of *cURL* to get get data from the web server hosted using Flask

You can learn more about cURL by executing the following in *Terminal*

    curl --help
<a name="firstprogram"></a>
## First Program

Open the nano editor by executing the following command

    nano

This should open up a blank text editor for you. Enter or Copy/Paste the following program into the editor

```python
from flask import  Flask 
app =  Flask(__name__)  

@app.route('/')  
def hello_world():  
	return  'Hello World\n'

if __name__ == '__main__':
	app.run()
```

Press `Ctrl+O` to save the program. This will prompt you to enter the filename for your program. Enter a filename (Example: `webserver.py` ) and press `Enter`. This will save your program

> Make sure you save the file with an extension *.py*

To exit from the editor, press `Ctrl+X`

Now that your program is ready to run, execute the following command to host the webserver

    python3 webserver.py

This should initialise the Web Server and you should see an output as follows in your *terminal*


<p align="center">
<img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/23%20Initializing%20a%20Local%20Flask%20Server.png" height=75% width=75%>
</p>

As you can see, the web service is available only for a device with IPv4 address 127.0.0.1 (a default address for the local machine, also known as *localhost*), it cannot be accessed from any other device over its LAN or Internet

In order to test the functioning of the Web Server, you either need to open another SSH session to the same *virtual machine* or run the Web Server in background mode

In order to start the Web Server in background mode, you may first quit the service by pressing `Ctrl+C`. Now you can start the Web Server by executing the following command

    python3 webserver.py &

This will initialise the Web Server and display logs as and when a client tries to access the web service

Pressing `Enter` will get you back to the Prompt where you can execute other commands you may have

Lets verify if the process for Web Server is running by executing the following command

    ps

You should now be able to see a new process with *python3*. Make note of the corresponding PID that will be required to kill the process / quit the Web Server when we don't need it anymore

Let's check if the *virtual machine* is listening to port 5000 as it should do, since we have initialised a Flask Web Server with default settings. Execute the following to do that

    netstat -ltn4

Lets execute a cURL command to check if the Web Server is responding to a request made to it by executing the following command

    curl '127.0.0.1:5000'

Since 127.0.0.1 is the address of local machine, the term `localhost` can also be used instead of the address

    curl 'localhost:5000'
Both of the above commands should give you the same response (in addition to the Web Server's log - giving you information about which IP address has tried to access what resource at what time and the HTTP request method)

By default, any request you made through cURL considers it to be a GET request. Hence, it is a good practice to assert the same by using the corresponding tag

    curl --request GET 'localhost:5000'

This will also give you the same response as above

To quit the Web Server, you can make use of the `kill` command along with the PID corresponding to the python3 process

    kill -9 PID

The following screenshot presents the commands executed and the corresponding responses

<p align="center">
<img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/24%20Intializing%20and%20Kill%20Web%20Server.png" height=75% width=75%>
</p>

Now that we have a very simple yet a fully functional Web Server deployed for the local machine, lets look into how we can make it available for other devices over the internet.
<a name="publicweb"></a>
## Making the Web Server available over Internet

The only change we need to make within the python program is to mention that the host shall accept requests from all IPv4 addresses (represented by `0.0.0.0`). To do this, lets edit the python program by opening the nano text editor using the following command

    nano webserver.py

Edit the last line of the program such that the program looks as following

```python
from flask import  Flask 
app =  Flask(__name__)  

@app.route('/')  
def hello_world():  
	return  'Hello World\n'

if __name__ == '__main__':
	app.run(host='0.0.0.0')
```

Once you make the changes, save the file by pressing `Ctrl+O` followed by `Enter` to confirm that you will save the file with the existing file name

Then press `Ctrl+X` to exit the editor

Now start the Web Server in background mode using the command

    python3 webserver.py &
Press `Enter` to get the prompt

Verify if the Web Server is listening from every IP address using the `netstat` command

    netstat -ltn4

Here is a screenshot of my *terminal*

<p align="center">
<img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/25%20Server%20listening%20from%20all%20IPs.png" height=75% width=75%>
</p>

The Address `0.0.0.0` before the port `5000` denotes that the service on port `5000` is listening to requests made every IPv4 addresses over the LAN or Internet

Now go to your browser and navigate to the following address

    http://IPv4 Public IP:5000

> The **IPv4 Public IP** here is the same IP address that you used to establish the SSH session in order to get access to the *terminal*

Inspite the fact that your Web Server is currently running and accepting requests from all over the Internet, you might not be able to get any response in your browser. This is due to AWS's virtual firewall known as Security Groups. 

> Security Groups in AWS manages the AWS services' (such as EC2, Lambda, Databases, etc) incoming and outgoing traffic through specific Inbound and Outbound rules
> 
> By default, when an EC2 instance is launched from AWS Console,  the *virtual machine* allows incoming requests only to port `22` and allows outgoing requests to all IP addresses and all ports. This is the reason why we are able to establish an SSH (port 22) connection to the *virtual machine* and it is able to communicate with every web service in the Internet.

Lets configure the Security Group of our *virtual machine* to accept incoming requests made to port `5000` so users across the Internet can access the Web Server you hosted. To add a new Inbound Rule to the *virtual machine*'s Security Group,

 1. Navigate to AWS Console

> Note: If you used your AWS Educate account to launch the *virtual machine*, you can access the AWS Console only by 
> - [`Signing in to AWS Educate`](https://aws.amazon.com/education/awseducate/)
> - Navigate to `AWS Account` menu item
> - Click the `AWS Educate Starter Account` button
>  - In the new browser tab that should have opened, select the class you used which launching the *virtual machine*  by clicking the triangle in the menu bar
>  - Click the `AWS Console` button

 2. Go to EC2 Dashboard and select the running Instance on which the *virtual machine* is working
 3. In the Instance Description (lower half of the Instances page), navigate to the Security Groups field
 4. Click on the security group attached to this *virtual machine*

> <p align="center">
> <img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/26%20Navigate%20to%20Security%20Group%20from%20Instance%20Description.png" height=75% width=75%>
> </p>
 5. Add an Inbound Rule with the following settings

> <p align="center">
> <img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/27%20Security%20Group%20Description.png" height=75% width=75%>
> </p>

 -- **Type**: `Custom TCP`
 -- **Protocol**: `TCP`
 -- **Port range**: `5000`
 -- **Source**: `Anywhere`
 -- **Description**: `Flask Server`

> <p align="center">
> <img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/28%20Edit%20Inbound%20Rule%20in%20Security%20Group.png" height=75% width=75%>
> </p>
 
 6. Click Save
 7. Verify that a new Inbound Rule to accept connections for port 5000 from any IPv4 address (`0.0.0.0`) is created successfully

Now, navigate to the URL you tried to access earlier

    http://IPv4 Public IP:5000
Wohoo! Now you should be able to see a response returned by your Web Server.

<p align="center">
<img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/29%20Browser%20Request.png" height=75% width=75%>
</p>

>You can also make a cURL request from your computer's Terminal (Linux / Mac) or Command Prompt (Windows) application and get the response 
>
>`curl --request GET 'http://IPv4 Public IP:5000'`
>
> <p align="center">
> <img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/30%20cURL%20Request%20from%20Terminal.png" height=75% width=75%>
> </p>
>Or you can visit https://reqbin.com and Send a GET request to `IPv4 Public IP:5000` to see the response
>
> <p align="center">
> <img src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/31%20GET%20Request%20in%20Redbin.png" height=75% width=75%>
> </p>
