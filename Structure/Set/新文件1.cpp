#include<stdio.h>

typedef struct Set{
	unsigned long long set;
}Set;

void init(Set *set){
	set->set = 0;
}

void add(Set *set, int i){
	long long int a = 1;
	a = a << i;
	set->set |= a;
}
void has(Set set, int i){
	long long int a = 1;
	a = a << i;
	if(a & set.set){
		printf("set has %d\n" , i);
	}
	else printf("set does not have %d\n" , i);
}

Set setUnion(Set a, Set b){
	Set c;
	c.set = a.set | b.set;
	return c;
}
Set setIntersect(Set a, Set b){
	Set c;
	c.set = a.set & b.set;
	return c;
}
Set setDifference(Set a, Set b){
	Set c;
	c.set = a.set ^ b.set;
	return c;
}

int main()
{
  Set a, b, c;
 
  init(&a);
  add(&a, 3);
  add(&a, 5);
  add(&a, 2);
 
  init(&b);
  add(&b, 3);
  add(&b, 7);
  add(&b, 9);
 
  c = setUnion(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setIntersect(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  c = setDifference(a, b);
  has(c, 2);
  has(c, 3);
  has(c, 5);
  has(c, 7);
  has(c, 9);
 
  return 0;
}
