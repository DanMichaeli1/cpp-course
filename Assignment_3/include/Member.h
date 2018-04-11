#include <string>
#include <vector>
#include <iostream>

#ifndef MEMBER_H
#define MEMBER_H

class Member{
	int numOfFollowing;
	int numOfFollowers;
	std::vector<Member*> followers;
    std::vector<Member*> following;

public:

	Member() {
		numOfFollowing = 0;
		numOfFollowers = 0;
		++counter;

	}
	~Member();

	void follow(Member & m);
	void unfollow(Member & m);
	int numFollowers() { return followers.size(); };
	int numFollowing() { return following.size(); };
    static int count(){return counter;};



private:
    static int counter;
};

#endif
