#ifndef _CELL_AUTOMATA_CELL_HPP
#define _CELL_AUTOMATA_CELL_HPP

namespace Core
{
	class Color;
}

namespace cellularAutomata
{
	class Cell
	{

	//Variables:
	public:
		Core::Color* color;
		float value;

	protected:
	private:

	//Functions:
	public:
		Cell();
		Cell(float red, float green, float blue);
		~Cell();

	protected:
	private:

	};
}

#endif 