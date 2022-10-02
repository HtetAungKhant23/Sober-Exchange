//
// Created by fatfat on 9/29/2022.
// Sober Exchange project
// Htet Aung Khant
// htetaung23.ha@gmail.com

#include<iostream>
using namespace std;

class Sober{
public:
    int locate = 0;
    int currentUserId = 0;
    string email[100];
    string username[100];
    string password[100];

    string toTransferName;
    float toTfSoberAmount = 0;
    float toTfBitcoinAmount = 0;
    float toTfEthAmount = 0;
    float toTfUsdtAmount = 0;

    float usdtAmount[100];
    float soberAmount[100];
    float bitCoinAmount[100];
    float ethAmount[100];

    float soberPrice = 50.69;
    float bitCoinPrice = 19295.63;
    float ethPrice = 1312.50;

    float stsober = 0;
    float stbitcoin = 0;
    float steth = 0;

    Sober(){
        cout<<endl<<"Welcome from sober exchange"<<endl<<endl;
    }

    int mainMenu();
    int signUp();
    int signIn();
    int mainPage();
    int allInfo();
    int buyCoin();
    int soberCoin();
    int bitCoin();
    int ethereumCoin();
    int myWallet();
    int updateProfile();
    int chUsername();
    int chPassword();
    int transfer();
    int tfusdt();
    int tfSober();
    int tfBitcoin();
    int tfEth();
    int swapCoin();
    int withdraw();
    int soberWd();
    int bitCoinWd();
    int ethWd();
    int usdtWd();
    int staking();
    int stakeSober();
    int stakeBitcoin();
    int stakeEth();
    int stopstake();
    int stopSober();
    int stopBitcoin();
    int stopEth();

};

int Sober::mainMenu() {
    int option = 0;
    do {
        cout << "Press 1 to Sign Up" << endl;
        cout << "Press 2 to Log In" << endl;
        cout << "Press 9 to Exit from this exchange" << endl;
        cin >> option;
        if (option == 1) {
            //sign up fun
            signUp();
        } else if (option == 2) {
            //sign in fun
            signIn();
        }else if (option == 9) {
            cout << "Thanks for using sober exchange" << endl;
            break;
        } else {
            cout << "Invalid Input" << endl;
        }
    }while(option != 9);
}

int Sober::signUp() {
    string em;
    string name;
    string passw;
    string comfpass;
    cout<<"Enter your Email : ";
    cin>>em;
    if(locate > 0) {
        for (int i = 0; i <= locate; i++) {
            if (em == email[i]) {
                cout << "This email is already created for account" << endl;
                signUp();
                break;
            }
        }
    }
    cout<<"Enter your User name : ";
    cin>>name;
    if(locate > 0) {
        for (int i = 0; i <= locate; i++) {
            if (name == username[i]) {
                cout << "This username is already taken" << endl;
                signUp();
                break;
            }
        }
    }
    cout<<"Enter your Password : ";
    cin>>passw;
    cout<<"Confirm your Password : ";
    cin>>comfpass;
    if(passw == comfpass){
        email[locate] = em;
        username[locate] = name;
        password[locate] = passw;
        cout<<"Sign up success"<<endl;
        usdtAmount[locate] = 0;
        soberAmount[locate] = 0;
        bitCoinAmount[locate] = 0;
        ethAmount[locate] = 0;
        locate++;
    }
}

int Sober::signIn() {
    string lemail;
    string lpass;
    cout<<"Enter your Email : ";
    cin>>lemail;
    cout<<"Enter your password : ";
    cin>>lpass;
    for(int i = 0; i <= locate; i++) {
        if (lemail == email[i] && lpass == password[i]) {
            currentUserId = i;
            cout << "sing in success" << endl;
            mainPage();
        }
    }
}


int Sober::mainPage() {
    int mainOption = 0;
    cout << endl << " Welcome " << username[currentUserId] << endl;
    do {
        cout << endl;
        cout << "Press 1 to buy coin" << endl;
        cout << "Press 2 to wallet" << endl;
        cout << "Press 3 to update profile" << endl;
        cout << "Press 4 to swapCoin" << endl;
        cout << "Press 5 to transfer" << endl;
        cout << "Press 6 to withdraw" << endl;
        cout << "Press 7 to stake" << endl;
        cout << "Press 8 to Log out" << endl;
        cout << "Press 9 to Quit from this exchange" << endl;
        cin >> mainOption;
        if(mainOption == 1){
         // buy coin fun
            buyCoin();
            break;
        }else if(mainOption == 2){
         // mywallet fun
            myWallet();
            break;
        }else if(mainOption == 3){
         // staking fun
            updateProfile();
            break;
        }else if(mainOption == 4){
         // swaping fun
            swapCoin();
            break;
        }else if(mainOption == 5){
         // transfer fun
            transfer();
            break;
        }else if(mainOption == 6){
         // withdraw fun
            withdraw();
            break;
        }else if (mainOption == 7){
            // staking fun
            staking();
            break;
        }else if(mainOption == 8){
            cout << "Logging out success" << endl;
            break;
        }else if(mainOption == 9){
            cout << "Thanks for using sober exchange" << endl;
            exit(1);
        }else{
            cout << "Invalid input" << endl;
        }

    }while( mainOption != 8 );
}

int Sober::buyCoin() {
    float usdtCoin;
    cout << " 1usdt coin = 1US dolor " << endl;
    cout << "Enter amount of usdt coin you want to buy : ";
    cin >> usdtCoin;
    usdtAmount[currentUserId] = usdtCoin;
    cout << " Transaction successful for buying " << usdtCoin << "$" << endl;
    mainPage();
}

int Sober::swapCoin() {
    int swapOption=0;
    do {
        cout << "Press 1 to swap from usdt to sober" << endl;
        cout << "Press 2 to swap from usdt to bitcoin" << endl;
        cout << "Press 3 to swap from usdt to ethereum" << endl;
        cout << "Press 4 to go back" << endl;
        cout << "Press 9 to exit from sober exchange" << endl;
        cin >> swapOption;
        if (swapOption == 1) {
            soberCoin();
            break;
        } else if (swapOption == 2) {
            bitCoin();
            break;
        } else if (swapOption == 3) {
            ethereumCoin();
            break;
        } else if (swapOption == 4) {
            mainPage();
            break;
        } else if (swapOption == 9) {
            exit(1);
        }
        else {
            cout << "Invalid Input" << endl;
        }
    } while (swapOption != 9);
}

int Sober::soberCoin() {
    cout << endl << "**Current price**" << endl;
    cout << " 1 sober coin = " << soberPrice << "$" << endl;
    cout << " Current usdt coin = " << usdtAmount[currentUserId] << endl;
    float usdt;
    cout << "Enter amount of usdt coin you want to swap : ";
    cin >> usdt;
    if ( usdt >= usdtAmount[currentUserId] ){
        cout << "Transaction Failed..." << endl;
        cout << "Not enough usdt coin to swap.." << endl;
    } else {
        soberAmount[currentUserId] = usdt / soberPrice;
        usdtAmount[currentUserId] = usdtAmount[currentUserId] - usdt;
        cout << "Transaction Successful..." << endl;
        cout << "Your sober coin = " << soberAmount[currentUserId] << "sob" << endl;
        cout << "Current usdt amount = " << usdtAmount[currentUserId] << "$" << endl;
    }

    swapCoin();
}

int Sober::bitCoin() {
    cout << "**Current price**" << endl;
    cout << " 1 bitcoin = " << bitCoinPrice << "$" << endl;
    cout << " your current usdt coin = " << usdtAmount[currentUserId] << endl;
    float usdt;
    cout<<"Enter amount of usdt coin you want to swap : ";
    cin>>usdt;
    if ( usdt >= usdtAmount[currentUserId] ){
        cout << "Transaction Failed..." << endl;
        cout << "Not enough usdt coin to swap.." << endl;
    } else {
        bitCoinAmount[currentUserId] = usdt / bitCoinPrice;
        usdtAmount[currentUserId] = usdtAmount[currentUserId] - usdt;
        cout << "Transaction Successful..." << endl;
        cout << "Your bitcoin = " << bitCoinAmount[currentUserId] << "bitcoin" << endl;
        cout << "Current usdt amount = " << usdtAmount[currentUserId] << "$" << endl;
    }

    swapCoin();
}

int Sober::ethereumCoin() {
    cout << "**Current price**" << endl;
    cout << " 1 ethereum = " << ethPrice << "$" << endl;
    cout << " your current usdt coin = " << usdtAmount[currentUserId] << endl;
    float usdt;
    cout<<"Enter amount of usdt coin you want to swap : ";
    cin>>usdt;
    if ( usdt >= usdtAmount[currentUserId] ){
        cout << "Transaction Failed..." << endl;
        cout << "Not enough usdt coin to swap.." << endl;
    } else {
        ethAmount[currentUserId] = usdt / ethPrice;
        usdtAmount[currentUserId] = usdtAmount[currentUserId] - usdt;
        cout << "Transaction Successful..." << endl;
        cout << "Your ethereum = " << ethAmount[currentUserId] << "eth" << endl;
        cout << "Current usdt amount = " << usdtAmount[currentUserId] << "$" << endl;
    }

    swapCoin();
}

int Sober::myWallet() {
        cout << " Usdt coin = " << usdtAmount[currentUserId] << "$" << "  | ";
        cout << " Sober coin = " << soberAmount[currentUserId] << "sob" << "  | ";
        cout << " Bitcoin = " << bitCoinAmount[currentUserId] << "bitcoin" << "  | ";
        cout << " Ethereum coin = " << ethAmount[currentUserId] << "eth" << endl;

        mainPage();
}

int Sober::updateProfile() {
    int chOption = 0;
    do {
        cout << endl << "Email = " << email[currentUserId] << endl;
        cout << "User Name = " << username[currentUserId] << endl;
        cout << "Password = " << password[currentUserId] << endl << endl;
        cout << "Press 1 to change user name" << endl;
        cout << "Press 2 to change password" << endl;
        cout << "Press 3 to back" << endl;
        cout << "Press 9 to exit this exchange" << endl;
        cin >> chOption;
        if (chOption == 1) {
            chUsername();
            break;
        } else if (chOption == 2) {
            chPassword();
            break;
        } else if (chOption == 3) {
            mainPage();
            break;
        } else if (chOption == 9) {
            cout << "Thanks for using sober exchange" << endl;
            exit(1);
        } else {
            cout << "Invalid input" << endl;
        }
    } while (chOption != 9);
}

int Sober::chUsername() {
    string newName;
    string copass;
    cout << "Enter new user name : ";
    cin >> newName;
    cout << "Enter password to change user name : ";
    cin >> copass;
    if (copass == password[currentUserId]) {
        username[currentUserId] = newName;
        cout << "User name was successfully changed" << endl;
        updateProfile();
    } else {
        cout << "Wrong password!" << endl;
        cout << "Try Again" << endl;
        chUsername();
    }
}

int Sober::chPassword() {
    string newPass;
    string coPass;
    cout << "Enter new password : ";
    cin >> newPass;
    cout << "Enter password to change new password : ";
    cin >> coPass;
    if (coPass == password[currentUserId]) {
        password[currentUserId] = newPass;
        cout << "Password was successfully changed" << endl;
        updateProfile();
    } else {
        cout << "Wrong password!" << endl;
        cout << "Try Again" << endl;
        chPassword();
    }
}

int Sober::staking() {
    int stakeOption = 0;
    do {
        cout << "Press 1 to stake Sober coin" << endl;
        cout << "Press 2 to stake Bitcoin" << endl;
        cout << "Press 3 to stake Ethereum" << endl;
        cout << "Press 4 to stop staking" << endl;
        cout << "Press 5 to back" << endl;
        cout << "Press 9 to exit from this exchange" << endl;
        cin >> stakeOption;
        if (stakeOption == 1) {
            cout << "By staking 1sob, can earn 0.1% weekly" << endl;
            stakeSober();
            break;
        } else if (stakeOption == 2) {
            cout << "By staking 1bitcoin, can earn 0.00001% monthly" << endl;
            stakeBitcoin();
            break;
        } else if (stakeOption == 3) {
            cout << "By staking 1ethereum, can earn 0.001% monthly" << endl;
            stakeEth();
            break;
        } else if (stakeOption == 4) {
            stopstake();
            break;
        } else if (stakeOption == 5) {
            mainPage();
            break;
        } else if (stakeOption == 9) {
            cout << "Thank you for using our exchange" << endl;
            exit(1);
        } else{
            cout << "Invalid input" << endl;
        }
    } while (stakeOption != 9);
}

int Sober::stakeSober() {
    if (soberAmount[currentUserId] == 0){
        cout << "Please swap sober coin first" << endl;
        mainPage();
    } else {
        cout << "Enter amount of sober coin you want to stake = ";
        cin >> stsober;
        if (stsober >= soberAmount[currentUserId]) {
            cout << "Transaction Failed..." << endl;
            cout << "Not enough sober coin to stake.." << endl;
            stakeSober();
        } else {
            soberAmount[currentUserId] = soberAmount[currentUserId] - stsober;
            cout << "Staking successful for " << stsober << "sob" << endl;
            cout << "Your sober coin = " << soberAmount[currentUserId] << "sob" << endl;
            staking();
        }
    }
}

int Sober::stakeBitcoin() {
    if (bitCoinAmount[currentUserId] == 0){
        cout << "Please swap bitcoin first" << endl;
        mainPage();
    } else {
        cout << "Enter amount of bitcoin you want to stake = ";
        cin >> stbitcoin;
        if (stbitcoin >= bitCoinAmount[currentUserId]) {
            cout << "Transaction Failed..." << endl;
            cout << "Not enough sober coin to stake.." << endl;
            stakeBitcoin();
        } else {
            bitCoinAmount[currentUserId] = bitCoinAmount[currentUserId] - stbitcoin;
            cout << "Staking successful for " << stbitcoin << "bitcoin" << endl;
            cout << "Your bitcoin = " << bitCoinAmount[currentUserId] << "bitcoin" << endl;
            staking();
        }
    }
}

int Sober::stakeEth() {
    if (ethAmount[currentUserId] == 0){
        cout << "Please swap ethereum coin first" << endl;
        mainPage();
    } else {
        cout << "Enter amount of ethereum coin you want to stake = ";
        cin >> steth;
        if (steth >= ethAmount[currentUserId]) {
            cout << "Transaction Failed..." << endl;
            cout << "Not enough ethereum coin to stake.." << endl;
            stakeEth();
        } else {
            ethAmount[currentUserId] = ethAmount[currentUserId] - steth;
            cout << "Staking successful for " << steth << "eth" << endl;
            cout << "Your ethereum coin = " << ethAmount[currentUserId] << "eth" << endl;
            staking();
        }
    }
}

int Sober::stopstake(){
    if (stsober > 0.01 || stbitcoin > 0.0001 || steth > 0.001) {
        int stopOption = 0;
        cout << "Press 1 to stop sober staking" << endl;
        cout << "Press 2 to stop bitcoin staking" << endl;
        cout << "Press 3 to stop ethereum staking" << endl;
        cout << "Press 4 to back" << endl;
        cin >> stopOption;
        if (stopOption == 1) {
            // stop sober staking
            stopSober();
        } else if (stopOption == 2) {
            // stop bitcoin staking
            stopBitcoin();
        } else if (stopOption == 3) {
            //stop eth staking
            stopEth();
        } else if (stopOption == 4) {
            staking();
        } else {
            cout << "Invalid input" << endl;
            stopstake();
        }
    } else {
        cout << "There is no any staking" << endl;
        mainPage();
    }
}

int Sober::stopSober() {
    if (stsober > 0.01) {
        soberAmount[currentUserId] = soberAmount[currentUserId] + (stsober + (stsober * 0.1));
        cout << "Successfully stopped staking" << endl;
        cout << "You earn = " << (stsober * 0.1) << "sob" << endl << endl;
        staking();
    } else {
        cout << "There is no any sober staking" << endl;
        stopstake();
    }
}

int Sober::stopBitcoin() {
    if (stbitcoin > 0.0001) {
        bitCoinAmount[currentUserId] = bitCoinAmount[currentUserId] + (stbitcoin + (stbitcoin * 0.00001));
        cout << "Successfully stopped staking" << endl;
        cout << "You earn = " << (stbitcoin * 0.00001) << "bitcoin" << endl << endl;
        staking();
    } else {
        cout << "There is no any bitcoin staking" << endl;
        stopstake();
    }
}

int Sober::stopEth() {
    if (steth > 0.001) {
        ethAmount[currentUserId] = ethAmount[currentUserId] + (steth + (steth * 0.001));
        cout << "Successfully stopped staking" << endl;
        cout << "You earn = " << (steth * 0.001) << "eth" << endl << endl;
        staking();
    } else {
        cout << "There is no any ethereum staking" << endl;
        stopstake();
    }
}

int Sober::transfer() {
    int tfOption = 0;
    cout << "Press 1 to transfer sober coin" << endl;
    cout << "Press 2 to transfer bitcoin" << endl;
    cout << "Press 3 to transfer ethereum coin" << endl;
    cout << "Press 4 to transfer usdt coin" << endl;
    cout << "Press 5 to back" << endl;
    cin >> tfOption;
    if (tfOption == 1) {
        tfSober();
    } else if (tfOption == 2) {
        tfBitcoin();
    } else if (tfOption == 3) {
        tfEth();
    } else if (tfOption == 4) {
        tfusdt();
    } else if (tfOption ==5) {
        mainPage();
    } else {
        cout << "Invalid input" << endl;
        transfer();
    }
}

int Sober::tfSober() {
    int receiver;
    cout << "Enter username to transfer : ";
    cin >> toTransferName;

    for (int i = 0; i <= locate; i++) {
        if (toTransferName == username[i]) {
            receiver = i;
            cout << "Enter sober amount to transfer : ";
            cin >> toTfSoberAmount;
            if (toTfSoberAmount >= soberAmount[currentUserId]) {
                cout << "Insufficient sober amount to transfer" << endl;
                transfer();
                break;
            } else {
                soberAmount[currentUserId] = soberAmount[currentUserId] - toTfSoberAmount;
                soberAmount[i] = soberAmount[i] + toTfSoberAmount;
                cout << "Successfully transferred " << toTfSoberAmount << "sob" << " to " << toTransferName << endl;
                transfer();
                break;
            }
        }
    }
}

int Sober::tfBitcoin() {

    cout << "Enter username to transfer : ";
    cin >> toTransferName;

    for (int i = 0; i <= locate; i++) {
        if (toTransferName == username[i]) {
            cout << "Enter bitcoin amount to transfer : ";
            cin >> toTfBitcoinAmount;
            if (toTfBitcoinAmount >= bitCoinAmount[currentUserId]) {
                cout << "Insufficient bitcoin amount to transfer" << endl;
                transfer();
                break;
            } else {
                bitCoinAmount[currentUserId] = bitCoinAmount[currentUserId] - toTfBitcoinAmount;
                soberAmount[i] = soberAmount[i] + toTfSoberAmount;
                cout << "Successfully transferred " << toTfBitcoinAmount << "bitcoin" << " to " << toTransferName << endl;
                transfer();
                break;
            }
        }
    }
}

int Sober::tfEth() {
    cout << "Enter username to transfer : ";
    cin >> toTransferName;

    for (int i = 0; i <= locate; i++) {
        if (toTransferName == username[i]) {
            cout << "Enter ethereum amount to transfer : ";
            cin >> toTfEthAmount;
            if (toTfEthAmount >= ethAmount[currentUserId]) {
                cout << "Insufficient ethereum amount to transfer" << endl;
                transfer();
                break;
            } else {
                ethAmount[currentUserId] = ethAmount[currentUserId] - toTfEthAmount;
                ethAmount[i] = ethAmount[i] + toTfEthAmount;
                cout << "Successfully transferred " << toTfEthAmount << "eth" << " to " << toTransferName << endl;
                transfer();
                break;
            }
        }
    }
}

int Sober::tfusdt() {
    cout << "Enter username to transfer : ";
    cin >> toTransferName;

    for (int i = 0; i <= locate; i++) {
        if (toTransferName == username[i]) {
            cout << "Enter usdt amount to transfer : ";
            cin >> toTfUsdtAmount;
            if (toTfUsdtAmount >= usdtAmount[currentUserId]) {
                cout << "Insufficient sober amount to transfer" << endl;
                transfer();
                break;
            } else {
                usdtAmount[currentUserId] = usdtAmount[currentUserId] - toTfUsdtAmount;
                usdtAmount[i] = soberAmount[i] + toTfUsdtAmount;
                cout << "Successfully transferred " << toTfUsdtAmount << "sob" << " to " << toTransferName << endl;
                transfer();
                break;
            }
        }
    }


}

int Sober::withdraw() {

    int wtdOption = 0;
    cout << "Press 1 to withdraw sober coin" << endl;
    cout << "Press 2 to withdraw bitcoin" << endl;
    cout << "Press 3 to withdraw ethereum coin" << endl;
    cout << "Press 4 to withdraw usdt coin" << endl;
    cout << "Press 5 to back" << endl;
    cin >> wtdOption;
    if (wtdOption == 1) {
        soberWd();
    } else if (wtdOption == 2) {
        bitCoinWd();
    } else if (wtdOption == 3) {
        ethWd();
    } else if (wtdOption == 4) {
        usdtWd();
    } else if (wtdOption ==5) {
        mainPage();
    } else {
        cout << "Invalid input" << endl;
        transfer();
    }
}

int Sober::soberWd() {
    float withdrawCoin = 0;
    if (soberAmount[currentUserId] != 0) {
        cout << "Enter sober amount to withdraw : ";
        cin >> withdrawCoin;
        if (withdrawCoin >= soberAmount[currentUserId]) {
            cout << "Insufficient sober coin to withdraw" << endl;
            soberWd();
        } else{
            soberAmount[currentUserId] = soberAmount[currentUserId] - withdrawCoin;
            cout << "Successfully withdraw " << withdrawCoin << "sob" << endl;
            mainPage();
        }
    } else {
        cout << "There is no sober coin in your wallet" << endl;
        withdraw();
    }
}

int Sober::bitCoinWd() {
    float withdrawCoin = 0;
    if (bitCoinAmount[currentUserId] != 0) {
        cout << "Enter bitcoin amount to withdraw : ";
        cin >> withdrawCoin;
        if (withdrawCoin >= bitCoinAmount[currentUserId]) {
            cout << "Insufficient bitcoin to withdraw" << endl;
            bitCoinWd();
        } else{
            bitCoinAmount[currentUserId] = bitCoinAmount[currentUserId] - withdrawCoin;
            cout << "Successfully withdraw " << withdrawCoin << "bitcoin" << endl;
            mainPage();
        }
    } else {
        cout << "There is no bitcoin in your wallet" << endl;
        withdraw();
    }
}

int Sober::ethWd() {
    float withdrawCoin = 0;
    if (ethAmount[currentUserId] != 0) {
        cout << "Enter ethereum coin amount to withdraw : ";
        cin >> withdrawCoin;
        if (withdrawCoin >= ethAmount[currentUserId]) {
            cout << "Insufficient ethereum coin to withdraw" << endl;
            ethWd();
        } else{
            ethAmount[currentUserId] = ethAmount[currentUserId] - withdrawCoin;
            cout << "Successfully withdraw " << withdrawCoin << "eth" << endl;
            mainPage();
        }
    } else {
        cout << "There is no ethereum coin in your wallet" << endl;
        withdraw();
    }
}

int Sober::usdtWd() {
    float withdrawCoin = 0;
    if (usdtAmount[currentUserId] != 0) {
        cout << "Enter usdt coin amount to withdraw : ";
        cin >> withdrawCoin;
        if (withdrawCoin >= usdtAmount[currentUserId]) {
            cout << "Insufficient usdt coin to withdraw" << endl;
            usdtWd();
        } else{
            usdtAmount[currentUserId] = usdtAmount[currentUserId] - withdrawCoin;
            cout << "Successfully withdraw " << withdrawCoin << "usdt" << endl;
            mainPage();
        }
    } else {
        cout << "There is no usdt coin in your wallet" << endl;
        withdraw();
    }
}

int main(){
    Sober sob;
    sob.mainMenu();

    return 0;
}
