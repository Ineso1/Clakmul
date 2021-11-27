
#ifndef USER_H
#define USER_H
#include <string>

    class User{

        private:
            std::string name;
            int age;
            std::string email;
            std::string password;
            std::string address;
            std::string cardNumber;
            int ccv;

        public: 
            
            //Constructores
            User();
            User(std::string,int,std::string,std::string,std::string,int,std::string);
            
            //Getters
            std::string getName()const;
            int getAge() const; 
            std::string getEmail()const;
            std::string getPassword()const;
            std::string getCardNumber()const;
            int getCcv()const;
            std::string getAddress()const;
            
            //Setters
            void setName(std::string);
            void setAge(int);
            void setEmail(std::string);
            void setPassword(std::string);
            void setAddress(std::string);
            void setCardNumber(std::string);
            void setCcv(int);

            //Impresion datos
            void PrintUser();

    };

#endif //USER_H
