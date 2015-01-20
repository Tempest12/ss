#ifndef _CORE_COLOR_HPP
#define _CORE_COLOR_HPP

namespace Core
{
	class Color
	{

	//Variables:
	public:
		
		float red  ;
		float green;
		float blue ;
		float alpha;

	protected:
	private:

	//Functions:
	public:

		Color();
		Color(float all);
		Color(float red  , float green, float blue );
		Color(float red  , float green, float blue , float alpha);

		~Color();

		void set(float all);
		void set(float red, float green, float blue);
		void set(float red, float green, float blue, float alpha);

	protected:
	private:


	//Static Stuff:
	
	//Variables:
	public:
	protected:
	private:

	//Functions:
	public:

		static Color* getRandomColor(void);

	protected:
	private:

	};
}

#endif