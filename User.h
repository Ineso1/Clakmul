#ifndef USER_H
#define USER_H
#include <string>
#include "Billing.h"

    class User{

        private:
            std::string name;
            int age;
            std::string email;
            int ccv;
            Billing billing;

        public: 
            
            //Constructores
            User();
            User(std::string,int,std::string,std::string,std::string);
            
            //Getters
            std::string getName()const;
            int getAge() const; 
            std::string getEmail()const;
            
            //Setters
            void setName(std::string);
            void setAge(int);
            void setEmail(std::string);
            

            //Impresion datos
            void PrintUser();

    };

#endif //USER_H
