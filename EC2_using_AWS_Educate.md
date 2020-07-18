# Using AWS Educate to connect to an EC2 instance

This guide is meant for IN4.0 Talent Academy candidates to access an Amazon Linux 2 based EC2 instance for the classwork related to hosting a website, exploring AWS services and preparing for the AWS certifications.


### Table of contents
1. [Signing up for AWS Educate account](#signupawseducate)
2. [Accessing AWS Console using AWS Educate](#awsconsoleaccess)
3. [Launching an EC2 Instance (Virtual Computer)](#launchec2)
4. [Connecting to the EC2 Instance via Termius](#connectssh)

<a name="signupawseducate"></a>
## Signing up for AWS Educate account 

Check your email where you should have received an email from support@awseducate.com

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/1%20Welcome%20Email.png">
</p>


Click on the link it has to follow up the application process and it should take you to the form something as follows

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/2%20Signup%20Form.png">
</p>
Fill the fields as suggested below

 - School or Institution Name: **Atria Institute of Technology**
 - Country: **India**
 - First Name: *Your First Name*
 - Last Name: *Your Last Name*
 - Email: *username*@**iot.atria.edu**
 - Graduation Month: *Your Graduation Month*
 - Graduation Year: *Highest of (Your graduation year, Current Year + 1)*
 - Birth Month: *Your birth month*
 - Birth Year: *Your birth year*
 - Promo Code: *blank*

Check the I'm not a robot field and prove the same and click Next

In the next page, scroll through the Terms and Conditions till the end, select I agree and click Submit

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/3%20Submit%20AWS%20Educate%20application.png">
</p>
After you submit, you should receive an email from support@awseducate.com asking you to confirm your email and the application

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/4%20Email%20verification.png">
</p>
Click on the verification link in the email and you're application for AWS Educate gets completed here.

In a few minutes, you should receive another email approving your application to the AWS Educate. 

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/5%20Approval%20of%20AWS%20Educate.png">
</p>
Feel free to click on the given link and setup a password.

To access your AWS Educate account, go to https://www.awseducate.com (and click on Sign in to AWS Educate) or go to https://www.awseducate.com/signin/SiteLogin 


Fill your AWS Educate account credentials and click **Sign In**

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/6%20Login%20AWS%20Educate.png">
</p>

<a name="awsconsoleaccess"></a>
## Accessing AWS Console using AWS Educate 

Once you sign in, you will see a number of options to

 - Learn through Career Pathways and Digital Badges
 - Build you portfolio
 - Find and apply for jobs from AWS Educate partner companies
 - Access your AWS account


<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/7%20AWS%20Educate%20Menubar.png">
</p>
We are interested in getting access to the AWS console, so click on the AWS account link in the menubar and it will take you to this page

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/8%20AWS%20tab%20in%20AWS%20Educate.png">
</p>

Click on the **AWS Educate Starter Account**

This will open a new tab in your browser and take you to the Workbench maintained by Vocareum platform to allow you to access the AWS account

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/9%20Vocareum%20Platform.png">
</p>

This page shows your AWS Account Status for the Starter Account. If you are enrolled into a class by your professor, you should be able to see more classes when you click the down arrow next to *My Classes* link on the menu bar

<p align="center">
<img width="50%" height="50%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/10%20AWS%20Educate%20AWS%20accounts.png">
</p>

Click on AWS Educate - Atria IoT Labs in this case to access the AWS account with higher credits

<p align="center">
<img width="50%" height="50%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/11%20Vocareum%20Atria%20IoT%20Labs%20AWS%20account.png">
</p>

As you make use of AWS services from these accounts, the remaining credits will decrease. You can find the cost of running AWS services from https://aws.amazon.com 

Note: The session time denotes the time until which the AWS account will be logged into the current browser. After the session time, you would be automatically logged out from the AWS account. However, any service that you created or started during this session will keep running until you run out of credits.

Click on the **AWS Console** button and a new tab will open with your AWS account. Make sure you have unblocked popups or click on the popup notification in your URL bar manually if you see no action after clicking on the AWS Console button.

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/12%20AWS%20account.png">
</p>

<a name="launchec2"></a>
## Launching an EC2 Instance (Virtual Computer) 

On the top left of your AWS console, go to Services and click on the EC2 link under Compute section. This will take you to the EC2 Dashboard where you find the EC2 resources configured in your account for the selected region

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/13%20EC2%20Dashboard.png">
</p>

Click on **Launch Instance** to select the Amazon Machine Image (AMI). We shall use Amazon Linux 2 operating system throughout this program, so select the same

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/14%20EC2%20Select%20AMI.png">
</p>

You will now be prompted to select the Instance Type. **t2.micro** comes for free (750hours/account) and it's technical specification is good enough for a beginner level web server so select t2.micro

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/15%20EC2%20Select%20Instance%20Type.png">
</p>

Click **Review and Launch**. This will take you to a page where you can review all the different configurations such as 

 - Storage Type and capacity
 - Security group
 - Tags

We will stick with the defaults. Click **Launch**

You will now be prompted to select the key pair required to access the EC2 Instance you are about to create. Select the *Create a new key pair* option from the drop-down menu and enter a name for key pair. The key pair acts as a secure password for you to login to your EC2 Instance / Virtual Machine.

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/16%20Create%20Key%20Pair.png">
</p>

**Download the key pair**. Notice the extension of the file once it is downloaded. We will refer to this file as the **.pem* file henceforth since this file has a .pem extension.

Once you download the key pair file, click on **Launch Instances**. This should take you to the following page

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/17%20View%20Instances.png">
</p>

Click on the **View Instances** button to look at the EC2 instance that is being provisioned for you. In a couple of minutes you should be able to see the status of this instance converting from *pending* to *running*

You should have a screen looking as follows (ignore my terminated instance). When you click on the checkbox or the Instance ID of the running instance you should be able to see all the instance details on the lower half of the screen

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/18%20Instances%20list.png">
</p>
The Instance description section give you most of the information about the EC2 instance you have selected. One of the things to be noted here is 

 - **IPv4 Public IP**: This is the IP address / Hostname you shall use while connecting to this instance via SSH

In order to connect to this instance, the other information you require are:

 - **Username**: ec2-user
 - **Port**: 22
 - **Key Pair**: *the \*.pem file you downloaded while launching the instance*

<a name="connectssh"></a>
## Connecting to the EC2 Instance via Termius

Download and Install the Termius software from https://termius.com for your operating system

Once the installation is complete, launch the Termius application and you should see the Termius window as follows (by skipping the Sign Up)

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/19%20Termius%20Window.png">
</p>

Click on **+New Host** and configure the following

 - In the **Label** field, enter a name you would like to refer the EC2 instance with
 - In the **Address** field, enter the **IPv4 Public IP** you noted in the AWS Console - Instance description
 - In the **Username** field, enter the Username of the EC2 instance (i.e., *ec2-user*)
 - In the **Password** field, click on *Keys*, then click *+KEY*, then click *File* and navigate to the directory where you downloaded the **.pem*, select it and click *Open*. Then click *SAVE*, followed by *SAVE* again

This should display the Host you just configured and saved.

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/20%20New%20Host%20Termius.png">
</p>
Now double click on the Host you just added and it should prompt you to confirm the fingerprint. This is a method of confirming your connection to a new computer over SSH. 

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/21%20Fingerprint%20confirmation.png">
</p>

Click **YES** to proceed

Now you should successfully be able to get access to the Terminal / Shell / Console of your EC2 instance

<p align="center">
<img width="75%" height="75%" src="https://raw.githubusercontent.com/sufiankaki/in40-docs/master/22%20Terminal.png">
</p>
Well done! You can now focus on the Application development and Server management henceforth.
