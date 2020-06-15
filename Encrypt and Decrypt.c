#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(void);
void decrypt(void);
void bruteforce(void);
void main()
{
	int opt;
step1:
	{
	printf(" _____________________________________ \n");
	printf("||                                   ||\n");
	printf("||***********************************||\n");
	printf("||\tEnter The Option             ||\n");
	printf("||***********************************||\n");
	printf("||1.Encrypt                          ||\n");
	printf("||2.Decrypt                          ||\n");
	printf("||3.Guess The Message(Without Key)   ||\n");
	printf("||___________________________________||\n");
	scanf("%d",&opt);
	if(opt<1 || opt>3)
		goto step1;
	}

	if(opt==1)
	{
		encrypt();
	}
	else if(opt==2)
	{
		decrypt();
	}
	else
	{
		bruteforce();
	}
}
void encrypt(void)
{
	int n,i;                                                    //For Storing Key and Iteration Values
	char text[50];                                              //For Storing PlainText
	char enc[50];                                               //For Storing CipherText
	printf("You have selected to Encrypt the text\n");
        printf("Enter the Text:");
	scanf(" %[^\n]*c",&text);                                   //Getting The Plaintext From The User
        printf("Enter the Key Value:");
        scanf("%d",&n);                                            //Getting Key Value From The User
        for(i=0;i<strlen(text);i++)  
	{
		if(text[i]==32)                                    //Checks For Blankspace(In ASCII Value)
			i++;
		if(isupper(text[i]))                              //Checks For If Plain Text Is In UpperCase
			text[i]=(text[i]+n-65)%26 +65;            //Shifting The Text Using Key
		else
			text[i]=(text[i]+n-97)%26 +97;  
	}
	printf("The Cipher Text is: %s",text);
	printf("The Key is %d",n);
}
void decrypt(void)
{
	int key,i;                                                 //For Storing Key And Iteration Value
	char txt[50];                                              //For Storing Cipher Text Or Encrypted Text
	char dec[50];                                              //For Storing Decrypted or The Actual Message
	printf("You have selected to Decrypt the text\n");
        printf("Enter the Text:   ");                              //Gets The Cipher or Encrypted Text As Input From The user 
        scanf(" %[^\n]*c",&txt);
        printf("Enter the Key Value:  ");                          //Gets The Key Used For Encrpting The Message
        scanf("%d",&key);
	for(i=0;i<strlen(txt);i++)
	{
		if(txt[i]==32)                                     //Checks For A BlankSpace(In ASCII Value)
			i++;
		if(isupper(txt[i]))                                //Checks For UpperCase Character
			txt[i]=(txt[i]-key-65)%26;                 //Shifts Each Characters Backward Using The Provided Key
		else
			txt[i]= 97+ ((txt[i]-key-97)%26 +26)%26;
	}
	printf("The Deciphered Text is %s and its Key is %d",txt,key);
}
void bruteforce(void)
{
	int key,i;                                                    //For Storing Key and Iterations
        char text[100];                                               //For Storing The Encrypted Message
        char possible[100];                                           //For storing The Possible Message For the Key
	printf("Enter the cipher");
        scanf(" %[^\n]*c",&text);                                     //Gets The Encrypted Text as Input
        strcpy(possible,text);                                        //Copies The Encrypted Text To The Possible variable
        for(key=0;key<26;key++)                                       //Iterates The Key Value From 0 to 25
        {
                for(i=0;i<strlen(text);i++)
                {
                        if(text[i]>='a' && text[i]<='z')              //Checks For LowerCase Character
                        {
                                possible[i]=text[i]-key;
                                if(possible[i]<'a')
                                        possible[i]+=26;
                        }
			 else if(text[i]>='A' && text[i]<='Z')        //Checks For UpperCase Character
                        {
                                possible[i]=text[i]-key;
                                if(possible[i]<'A')
                                        possible[i]+=26;
                        }
                }
                printf("The decrypted txt is %s and The Key is %d\n",possible,key);         //Prints The Decrypted Text For The Assigned Key Value
        }
}

