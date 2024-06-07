#include "Products.h"
#include <iostream>
#include"Class.h"


using namespace std;


int main()
{
    User user;
    Products x;
    store ss; 
    ShoppingCart selected;
    Wishlist product_wl;
    Receipt receipt;
    string product_name;
    Payment payment;
    shippingTracker shippingTracker;
    Clock clock;
    giftcard card(25.0);

    int num;
    int choice;
    int choice_product;
    double discountedPrice = card.applyDiscount(receipt);


    bool quit = true;
    cout << "\t\t\t\t------------------  fashion store  ------------------"<<endl;
    cout << "\t\t\t\t|                                                   |" << endl;
    cout << "\t\t\t\t|                   1)Administrator                 |"<<endl;
    cout << "\t\t\t\t|                                                   |" << endl;
    cout << "\t\t\t\t|                   2)User                          |"<<endl;
    cout << "\t\t\t\t|                                                   |" << endl;
    cout<<  "\t\t\t\t-----------------------------------------------------"<<endl;
    
    clock.displayCurrentTime();
    shippingTracker.displayShippingDetails();

    start:

    //loop again if he enter a wrong input

    cin >> num;
    //Administrator
    if (num == 1) {
        do
        {
            system("CLS");
            int option;

            cout << "\t\t\t\t\t-------------------------------------" << endl;
            cout << "\t\t\t\t\t|             MAIN MENU             |" << endl;
            cout << "\t\t\t\t\t|-----------------------------------|" << endl;
            cout << "\t\t\t\t\t|        1) ADD NEW PRODUCT         |" << endl;
            cout << "\t\t\t\t\t|        2) SHOW ALL PRODUCTS       |" << endl;
            cout << "\t\t\t\t\t|        3) SEARCH FOR A PRODUCT    |" << endl;
            cout << "\t\t\t\t\t|        4) UPDATE PRODUCTS         |" << endl;
            cout << "\t\t\t\t\t|        5) DELETE A PRODUCT        |" << endl;
            cout << "\t\t\t\t\t|        6) QUIT                    |" << endl;
            cout << "\t\t\t\t\t|-----------------------------------|" << endl;

           // date.displayDate();

            cout << "Enter your choice here :  "; 
            cin >> option;

            switch (option)
            {
            case 1:
                x.AddProduct();
                break;

            case 2:
                x.ListProduct();
                break;

            case 3:
                cin.ignore();
                cout << "search by product name : ";
                getline(cin, product_name);
                x.SearchProduct(product_name);
                break;

            case 4:
                cin.ignore();
                cout << "search by product name : ";
                getline(cin, product_name);
                x.UpdateProduct(product_name);
                break;

            case 5:
                cin.ignore();
                cout << "enter the product's name to be deleted: ";
                getline(cin, product_name);
                x.DeleteProduct(product_name);
                cin.ignore();
                system("CLS");
                break;
            case 6:
                quit = false;
                break;

            default:
                cout << "you entered an invalid command , enter any key to continue";
                cin.get();
                break;
            }

            cin.get();
            cin.get();

        } while (quit);
        cout << "thank you for using our fashion store";
        cin.get();
       

    }  //User
    else if (num == 2) {

       // user.enter_data();
        while (true) {
            try {
                //p.enter_data();
                // If the user entered proper input, break out of the loop
                break;
            }
            catch (const std::exception& e) {
                // If the user entered improper input, display an error message and prompt them to re-enter their information
                std::cerr << "Error: " << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        
        do
        {
            system("CLS");
            int option;
        mainuser:
            cout << "\t\t\t\t_____________________________________________" << endl;
            cout << "\t\t\t\t|                MAIN MENU                   |" << endl;
            cout << "\t\t\t\t|____________________________________________|" << endl;
            cout << "\t\t\t\t|            1) About US                     |" << endl;
            cout << "\t\t\t\t|            2) SHOW ALL PRODUCTS            |" << endl;
            cout << "\t\t\t\t|            3) SEARCH FOR A PRODUCT         |" << endl;
            cout << "\t\t\t\t|            4) WISHLIST                     |" << endl;
            cout << "\t\t\t\t|            5) SHOPPING CART                |" << endl;
            cout << "\t\t\t\t|            6) <-Back                       |" << endl;
            cout << "\t\t\t\t|            7) QUIT                         |" << endl;
            cout << "\t\t\t\t|____________________________________________|" << endl;
            cout << "enter your choice here :  "; 
            cin >> option;

            switch (option)
            {
            case 1:
                ss.ShowInfo();
                break;

            case 2:
                x.ListProduct();
                cout << "\t\t\t\t________________ ADD TO ________________"<<endl;
                cout << "\t\t\t\t|          1)Shopping cart            |"<< endl;
                cout << "\t\t\t\t|          2)wishlist                 |"<< endl;
                cout << "\t\t\t\t______________________________________" << endl;
                cout << "Enter: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    goto addproduct;
                    break;
                case 2:
                    goto addtowishlist;
                    break;
                default:
                    cout<<"error";
     }
                break;

            case 3:
                cin.ignore();
                cout << "search by product name : ";
                getline(cin, product_name);
                x.SearchProduct(product_name);

                break;
            
            case 5:
                cout << "\t\t\t\t    SHOPPING CART     " << endl;
                cout << "\t\t\t\t=====================" << endl;
                cout << "\t\t\t\t   1)ADD PRODUCT     " << endl;
                cout << "\t\t\t\t   2)Show SC         " << endl;
                cout << "\t\t\t\t   3)<-back          " << endl;
                cout << "\t\t\t\t=====================" << endl;
                cin >> choice_product;

                switch (choice_product) {
                case 1:
                addproduct:

                    selected.AddProducttoSC();

                    break;
          
                case 2:
                    selected.showSCproducts();
                    receipt.GenerateReceipt(selected);
                    cout << "Discounted price: $" << discountedPrice << std::endl;
                    cout << "enter: ";
                    payment.processPayment();

                    break;
                case 3:
                    goto mainuser;
                    break;
                default:
                    cout << "you entered invalid number";

                }
                cin.get();
                break;

            case 4:
                cout << "\t\t\t\t        WISHLIST     " << endl;
                cout << "\t\t\t\t=====================" << endl;
                cout << "\t\t\t\t   1)ADD PRODUCT     " << endl;
                cout << "\t\t\t\t   2)Show WL         " << endl;
                cout << "\t\t\t\t   3)<-back          " << endl;
                cout << "\t\t\t\t=====================" << endl;
                cin >> choice_product;

                switch (choice_product) {
                case 1:
                    addtowishlist:
                    product_wl.AddProducttoWL();

                    break;
            
                case 2:
                    product_wl.showWLproducts();
                    break;
                case 3:
                    goto mainuser;
                    break;
                default:
                    cout << "you entered invalid number";

                }
                break;

            case 6:
                quit = false;
                break;

            default:
                cout << "you entered an invalid command , enter any key to continue";
                cin.get();
                break;
            }

            cin.get();
            cin.get();


        } while (quit);
        cout << "thank you for using our fashion store";
        cin.get();



    }
    else {
        cout << "Invalid input !,\nEnter:";
        goto start;
    }

    }

