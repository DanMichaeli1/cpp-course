#include <list>
#include <iostream>
#include "Member.h"


Member::~Member() {
//    while(!this->followers.empty()){followers[0]->unfollow(*this);}
//    while(!this->following.empty()){following[0]->unfollow(*this);}

	for(Member* m : followers){m->unfollow(*this);}
	for(Member* m : following){this->unfollow(*m);}
	--counter;
}

void Member::follow(Member & m) {
    bool alreadyFollowing = false;
    if(&m==this)alreadyFollowing = true;
    unsigned i = 0;
    while(!alreadyFollowing && i < following.size())
    {
             if(following[i]==&m) alreadyFollowing = true;
             i++;
    }

    if(!alreadyFollowing)
    {
        following.push_back(&m);
        m.followers.push_back(this);
    }
}

void Member::unfollow(Member & m) {
    unsigned i = 0;
    //checking if m is in the following list
    for(; i < following.size(); i++)
    {
        if(following[i]==&m) break;
    }
    if(i<following.size()) //if m is found then i must be smaller than following.size
    {
        following.erase(following.begin() + i);
    }
    i = 0;
    //checking m's follower's list to delete the unfollower
    for(; i < m.followers.size(); i++)
    {
        if(m.followers[i]==this) break;
    }
    if(i<m.followers.size())
    {
        m.followers.erase(m.followers.begin() + i);
    }
}

int Member::counter = 0;

