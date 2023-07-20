#ifndef PLight_H
#define PLight_H

enum PLightMode { ct, colorgamut, xy };

class PLight {

    private:

        std::string ip;
        std::string user;

    public:

        PLight( const std::string &id );

        bool get_is_on();
        PLightMode get_mode();

        void set_state( bool &data );

};

#endif
