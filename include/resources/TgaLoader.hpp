#ifndef _RESOURCES_TGALOADER
#define _RESOURCES_TGALOADER

namespace Resources
{
    class Texture;

    class TgaLoader
    {
    //Static Functions:
    public:

        static Texture* loadFromFile(const std::string& fileName);

    protected:
    private:
    };
}

#endif