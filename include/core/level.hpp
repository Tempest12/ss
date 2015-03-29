#ifndef _CORES_LEVEL_HPP
#define _CORES_LEVEL_HPP

namespace Core
{
    class Level
    {
    //Variables:
    public:
    protected:
    private:

    //Functions:
    public:

        virtual Level* getNextLevel(void)   = 0;
        virtual void   draw(void)           = 0;
        virtual bool   update(float time)   = 0;

    protected:
    private:
    };
}

#endif