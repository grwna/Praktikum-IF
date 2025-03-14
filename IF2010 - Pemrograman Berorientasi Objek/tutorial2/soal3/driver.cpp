#include <iostream>
#include "Authenticator.hpp"

using namespace std;

int main() {
    Authenticator auth;

    auth.registerUser("Alice", "pass123", false);
    auth.registerUser("Bob", "secure456", true); 
    auth.registerUser("Alice", "pass123", false);

    cout << endl;

    auth.login("Alice", "wrongpass");
    auth.login("Alice", "pass123");
    auth.accessResource();
    auth.setResource("New Secret Data");
    auth.logout();

    cout << endl;

    auth.login("Bob", "secure456");
    auth.accessResource();
    auth.setResource("Top Secret Data!");
    auth.logout();

    cout << endl;
    
    auth.accessResource();

    return 0;
}
