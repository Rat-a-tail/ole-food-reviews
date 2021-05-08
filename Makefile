UserDriver:	User.o	UserDriver.o
	g++ -g -Wall -o UserDriver User.o UserDriver.o

User.o:	User.cpp	User.h
	g++ -g -Wall -c User.cpp

UserDriver.o:	UserDriver.cpp	User.h
	g++ -g -Wall -c UserDriver.cpp

UserArrayDriver:	UserArray.o	UserArrayDriver.o
	g++ -g -Wall -o UserArrayDriver UserArray.o UserArrayDriver.o ../react.o -lcurl

UserArray.o:	UserArray.cpp	UserArray.h
	g++ -g -Wall -c UserArray.cpp

UserArrayDriver.o:	UserArrayDriver.cpp	UserArray.h
	g++ -g -Wall -c UserArrayDriver.cpp

Meal_Array.o:  Meal_Array.cpp Meal_Array.h 
	g++ -g -Wall -c Meal_Array.cpp

Meal_Array_Driver.o:  Meal_Array_Driver.cpp Meal_Array.h 
	g++ -g -Wall -c Meal_Array_Driver.cpp

Meal_Array_Driver:  Meal_Array.o Meal_Array_Driver.o 
	g++ -g -Wall -o Meal_Array_Driver Meal_Array.o Meal_Array_Driver.o 



