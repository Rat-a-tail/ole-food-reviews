#include<iostream>
using namespace std;

int getlenstring(const char *word){
    int len = 0;
    while (word[++len] != 0){}
    return len+1;
}

class Review {
    int stars;
    char *date;
    char *username;
    char *meal;

public:
    Review(int s, char *d, char *u, char *m) {
        cerr << "Review constructor initialized" << endl;
        if (s < 1) {
            stars = 1;
        }
        if (s < 6) {
            stars = s;
        }
        else {
            stars = 5;
        }
        int datelen = getlenstring(d);
        int userlen = getlenstring(u);
        int meallen = getlenstring(m);
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = d[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = u[i];
        }
        meal = new char[meallen];
        for (int i = 0; i < meallen; ++i) {
            meal[i] = m[i];
        }
    }

    Review() {
        cerr << "Review default constructor initialized" << endl;
        stars = -1; //NOTE: When implementing this on React, we should make it so that if a star rating is -1, it displays a special message to the effect of "NO REVIEW" or something.
        date = new char[8];
        date[0] = 'X';
        date[1] = 'X';
        date[2] = '/';
        date[3] = 'X';
        date[4] = 'X';
        date[5] = '/';
        date[6] = 'X';
        date[7] = 'X';
        date[8] = 0;
        username = new char[8];
        for (int i = 0; i < 7; ++i) {
            username[i] = 'x';
        }
        username[8] = 0;
        meal = new char[8];
        for (int i = 0; i < 7; ++i) {
            meal[i] = 'x';
        }
        meal[8] = 0;
    }

    Review(const Review &input) {
        cerr << "Review copy constructor initialized" << endl;
        int datelen = getlenstring(input.date);
        int userlen = getlenstring(input.username);
        int meallen = getlenstring(input.meal);
        stars = input.stars;
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = input.date[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = input.username[i];
        }
        meal = new char[meallen];
        for (int i = 0; i < meallen; ++i) {
            meal[i] = input.meal[i];
        }
    }

    ~Review() {
        cerr << "Review destructor initialzied" << endl;
        delete [] date;
        delete [] username;
        delete [] meal;
    }

    int get_stars() {return stars;}
    char *get_date() {return date;}
    char *get_username() {return username;}
    char *get_meal() {return meal;}

    void set_stars(int s) {stars = s;}
    void set_date(char *d) {
        delete [] date;
        date = new char[getlenstring(d)];
        for (int i = 0; i < getlenstring(d); ++i) {
            date[i] = d[i];
        }
    }
    void set_username(char *u) {
        delete [] username;
        username = new char[getlenstring(u)];
        for (int i = 0; i < getlenstring(u); ++i) {
            username[i] = u[i];
        }
    }
    void set_meal(char *m) {
        delete [] meal;
        meal = new char [getlenstring(m)];
        for (int i = 0; i < getlenstring(m); ++i) {
            meal[i] = m[i];
        }
    }
    void test_display() {cerr << get_stars() << " " << get_date() << " " << get_username() << " " << get_meal() << endl;}
};

class Review_Array {
    int length;
    Review *review_array;

public:
    Review_Array(int l) : length(l) {
        cerr << "Review_Array constructor initialized" << endl;
        review_array = new Review[length];
    }

    Review_Array() {
        cerr << "Review_Array default constructor initialized" << endl;
        length = 0;
        review_array = new Review[length];
    }

    ~Review_Array() {
        cerr << "Review_Array destructor initialized" << endl;
        delete [] review_array;
    }

    Review & operator[](int i) {
        return review_array[i];
    }

    void edit_entry(int i, Review newdata) {
        review_array[i].set_stars(newdata.get_stars());
        review_array[i].set_date(newdata.get_date());
        review_array[i].set_username(newdata.get_username());
        review_array[i].set_meal(newdata.get_meal());
    }

    /*void add_entry(Review latest) {
        //adds new entry to the end of the array by deallocating the old array and copying the contents into a new array one index longer that contains the new entry at the end
        Review_Array temp(length + 1);
        for (int i = 0; i < length; ++i) {
            temp[i] = review_array[i];
        }
        temp[length + 1] = latest;
        delete [] review_array;
        Review_Array review_array(length + 1);
        review_array = temp;
        delete [] temp;
    }*/

    void delete_entry(int i) {
        //deletes the entry at the corresponding index, deallocates the old array and copies the contents into a new array that's one index shorter, so the index of every entry after the entry that was deleted is decreased by one
    }

    void test_display() {
        //displays the entire contents of the array
    }
};

int main() {
    Review newreview(3, "12/12/12", "martin52", "pizza");
    Review newreview2(2, "2/2/2", "tululu2", "tofu");
    Review_Array test(4);
    test[2].test_display();
    test.edit_entry(2, newreview);
    test[2].test_display();
    /*test.add_entry(newreview2);
    test[2].test_display();*/
}