/*
*
*/
#include <account.h>
#include <utilities.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <list>


class AccountManager{
public:
	std::string transactions_log;
	std::list<Account> accounts_in_file;
	std::string session_type;
	Utilities utility_functions;
	Account* current_account;
	
	AccountManager(){
		this->transactions_log = "";
	}
	void login(){
		//an example usage of the this->utility_functions
		this->session_type = this->utility_functions.prompt("Please Enter the Kind of Session: ","",{"standard","admin"});
		
		this->accounts_in_file = this->utility_functions.loadAccountInformation("Accountsfile.txt");
		
		if(this->session_type=="standard"){
			std::string account_name = this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = utility_functions.getAccountFromName(account_name,accounts_in_file);
			
			if (this->current_account == nullptr){
				this->utility_functions.prompt("Invalid Account Name.");
			}
		}
	}

	void withdrawal(){
		if(session_type=="admin"){
			std::string account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = this->utility_functions.getAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.prompt("Invalid Account Name.");
			}
		}
		
		
		double account_number = std::stod(this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}"));
		if (account_number != this->current_account->getAccountNumber()){
			return;
		}
			
		double withdrawal_amount= std::stod(this->utility_functions.prompt("Please Enter the Withdrawl Ammount: ","\\d{0,5}")); //needs changing reg to upper amount limit

		double current_balance = this->current_account->getBalance();
		if ( current_balance > withdrawal_amount){
			current_account->setBalance(current_balance-withdrawal_amount);
			this->utility_functions.prompt("Transaction successful.");
		}
		else{
			this->utility_functions.prompt("Insufficient funds.");
		}


		//if successful withdrawal; add withdrawal transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(withdrawal_amount)+" "+this->current_account->getAccountType());
	}

	void transfer(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");//not sure how to limit to 5 digits
		std::string account_number_to =
		double transfer_amount=

		//transfer amount to account2 from account1


		//if successful transfer; add transfer transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(transfer_amount)+" "+this->current_account->getAccountType());
		this->transactions_log.append("04 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(transfer_amount)+" "+this->current_account->getAccountType());

	}

	void paybill(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");
		std::string company_paidto=
		double amount_to_pay=

		//paybill amount to company


		//if successful paybill; add paybill transaction information in transactions_log list
		this->transactions_log.append("03 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+amount_to_pay+" "+this->current_account->getAccountType());

	}

	void deposit(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");
		double amount_deposit=

		//deposit amount


		//if successful deposit; add deposit transaction information in transactions_log list
		this->transactions_log.append("04 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+amount_deposit+" "+this->current_account->getAccountType());
	}

	void createAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");

			//initial balance
			account_balance=

			//create account with unique Please Enter the Account Number: 


			//if account created; add account information in transactions_log list
			this->transactions_log.append("05 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+account_balance+" "+this->current_account->getAccountType());

		}
	}

	void deleteAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

		//delete account from system


		//if account deleted; add deleted account information in transactions_log list
		this->transactions_log.append("06 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType());
		}
	}

	void enableAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//enabe account; account status from D to A


			//if account enabled; add enabed account information in transactions_log list
			this->transactions_log.append("09 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+this->current_account.account_balance+" "+this->current_account.account_status);
		}
	}

	void disableAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//disable account; account status from A to D


			//if account disabled; add disabled account information in transactions_log list
			this->transactions_log.append("07 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+this->current_account.account_balance+" "+this->current_account.account_status);
		}
	}

	void changePlan(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//changeplan for account; account type should be change (S/NS)


			//if account plan is changed; add account plan information in transactions_log list
			this->transactions_log.append("08 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+this->current_account.account_balance+" "+this->current_account->getAccountType());

		}
	}

	void logout(){
		//end session

		//if logout; add logout information in transactions_log list
		this->transactions_log.append("00 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType());

		//output transaction file log
		for(std::list<std::string>::const_iterator i = transactions_log.begin(); i != transactions_log.end(); ++i){
			ofstream outfile;
			outfile.open("transaction_log.txt");
			outfile << i->c_str() << endl;
			outfile.close();
		}

	}
};
