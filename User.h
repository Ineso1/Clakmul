#ifndef USER_H
#define USER_H
#include <string>
#include "Billing.h"
//Benjamin Gutierrez
    class User{

        private:
            std::string name;
            std::string age;
            std::string email;
            Billing billing;

        public: 
            
            //Constructores
            User();
            User(std::string,std::string,std::string,std::string,std::string,std::string);
            
            //Getters
            std::string getName()const;
            std::string getAge() const; 
            std::string getEmail()const;
            Billing getBilling()const;
            
            //Setters
            void setBilling(std::string,std::string,std::string);
            void setName(std::string);
            void setAge(std::string);
            void setEmail(std::string);
            

            //Impresion datos
            void PrintUser();

    };

#endif //USER_H
