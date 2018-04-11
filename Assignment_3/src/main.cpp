#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
    cout << "  " << Member::count()<<endl; // 4
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
    cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count(); // 3
	cout << endl;

    avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);
            avi.unfollow(beni);
            avi.follow(avi);
            avi.unfollow(avi);
	cout <<avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
    cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 0 0
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0

	cout << endl;
	test1();
	cout << endl;
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0

	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout <<  Member::count() << endl; // 3
}
