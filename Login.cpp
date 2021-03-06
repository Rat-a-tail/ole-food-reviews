#include"../react.h"
#include "UserArray.h"
#include "User.h"
//#include "ReviewArray.h"
//#include "Meal_Array.h"
//#include "Station_Array.h"


int main() {
  _init();
  std::ifstream f("Userinfo.txt");
  UserArrayP sto(f);
  /*
      Meal* arr;
    arr = new Meal[20]; // default contructor called here, first built the stations empty then fill themw ith the meal information:
     // might need a method(add) to do the thing above.--> station.
    //Soup station
    Meal a("Pea Soup");
    Meal b("Jar Jar Binks California Meldley");
    //Home station
    Meal c("Tautaun (Beef) Red Wine Braised Pot Roast");
    Meal d(" Carbonite Roasted Spicy Potatoes");
    Meal e ("Jakku Noodles");
    // Tortilla station
    Meal f("Sofrito Pinto Beans");
    Meal g("Chipotle Black Beans");
    Meal h("Achiote chicken Pinto Tinga");
    Meal i("Arroz Amarillo");

    //Pizza station
    Meal j("Wampa Sausage and Swiss Chard Pizza");
    Meal k("Rancor Pepperoni Pizza with Hastings Dairy");
    Meal l("Pizza");
    // Pasta station
    Meal m("Roasted Chicken");
    Meal n("Pasta");
    Meal o("Roasted Local Vegetables");
    Meal p("Sauce Marinara");
    Meal q("Garlic Peppercorn Sauce");
    //delete [] arr;

    station Soup;
    Soup.add_meal(a);
    Soup.add_meal(b);
    //Soup.display();

    station Home;
    Home.add_meal(c);
    Home.add_meal(d);
    Home.add_meal(e);
    //Home.display();

    station Tortilla;
    Tortilla.add_meal(f);
    Tortilla.add_meal(g);
    Tortilla.add_meal(h);
    Tortilla.add_meal(i);

    station Pizza;
    Pizza.add_meal(j);
    Pizza.add_meal(k);
    Pizza.add_meal(l);

    station Pasta;
    Pasta.add_meal(m);
    Pasta.add_meal(n);
    Pasta.add_meal(o);
    Pasta.add_meal(p);
    Pasta.add_meal(q);

    station **array_of_stations;
    int num_stations = 5;
    array_of_stations = new station*[num_stations];
    array_of_stations[0] = &amp;Soup;
    array_of_stations[1] = &amp;Home;
    array_of_stations[2] = &amp;Tortilla;
    array_of_stations[3] = &amp;Pizza;
    array_of_stations[4] = &amp;Pasta;


    Soup.retrieve_information(num_stations, array_of_stations);

    Home.retrieve_information(num_stations, array_of_stations);

    Tortilla.retrieve_information(num_stations, array_of_stations);

    Pizza.retrieve_information(num_stations, array_of_stations);

    Pasta.retrieve_information(num_stations, array_of_stations);

    put_stationarray_in_global_mem(0, array_of_stations, 5);
    a.print_to_file_meal(&quot;Meal2.txt&quot;);

  */
  if (_just_starting()) {
    //cerr << "just_starting" <<endl;
    add_yaml("welcome.yaml");
    //cerr <<"after add_yaml" <<endl;
    _put_raw(20, "Ole Food Reviews");
    _put_raw(0, "Username:");  // null bye appended automatically
    _put_raw(10, "Password:");
    _put_raw(40, "submit");
    _put_raw(50, "New User");
    _put_raw(60, "Today's Meals");
    _put_raw(80, "Archive");
    _put_raw(90, "St Olaf username: ");
    _put_raw(110, "Create Password: ");
    _put_raw(130, "Succesfully Registered");
    _put_raw(160, "Incorrect Username or Password");
    _put_raw(190, "Login");
    _put_raw(200, "Login Successful");
    _put_raw(220, "Register");
    _put_raw(230, "");
    _put_raw(250, "");
    _put_raw(270, "");
    //cerr <<"after put raw statement" <<endl;
  }
  if (_received_event()) {
    //cerr <<"received_event" <<endl;
    if (_event_id_is("login")){
      add_yaml("Login.yaml");
    }
    else if (_event_id_is("submit")) {
      //cerr<< "submit" <<endl;
      char *s = &(_global_mem[230]);
      char *q = &(_global_mem[250]);
    	bool a = sto.checking(s, q);
	
      if (a){
	      //cerr << "correct" <<endl;
        add_yaml("mainpage.yaml");
      }
      
      else{
	cerr << "Incorrect Username or Password" <<endl;
        add_yaml("Login.yaml");
      }
    }
    else if (_event_id_is("register")){
      char *s = &(_global_mem[230]);
      char *q = &(_global_mem[250]);
      add_yaml("mainpage.yaml");
      User input(s, q);
      //input.display();
      sto.addUser(input);
      //sto.store_global(5);
      sto.print_to_file("Userinfo.txt");
    }
    
    else if (_event_id_is("newuser")) {
      add_yaml("newuser.yaml");
    }
    
    else if(_event_id_is("today")){
        add_yaml("today.yaml");
    }

    else if(_event_id_is("archive")){
        add_yaml("archive.yaml");
    }
  }
  _quit();
}


