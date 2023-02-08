#pragma once
#define SingletonDefaultConstruct(type)  		private:\
												type() = default;\
												~type()= default;\
												type(type& instance) = delete;\
												type& operator=(const type& instance) = delete;\
												public:\
												static type& GetInstance()\
												{\
													static type instance;\
													return instance;\
												}

#define SingletonSelfConstruct(type)  			private:\
												type();\
												~type();\
												type(type& instance) = delete;\
												type& operator=(const type& instance) = delete;\
												public:\
												static type& GetInstance()\
												{\
													static type instance;\
													return instance;\
												}