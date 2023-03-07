#include <iostream>

using namespace std;

class tcp_octet_stream;
class tcp_state;
class tcp_listen;
class tcp_closed;
class tcp_established;

class tcp_connection
{
public:
    tcp_connection() { _state = tcp_closed::instance(); }
    void active_open() { _state->active_open(this); }
    void passive_open() { _state->passive_open(this); }
    void close() { _state->close(this); }
    void send() { _state->send(this); }
    void acknowledge() { _state->acknowledge(this); }
    void synchronize() { _state->synchronize(this); }

    void process_octet(tcp_octet_stream* tcp_oct) {}

private:
    friend class tcp_state;
    void change_state(tcp_state* tcp_st) { _state = tcp_st; }

private:
    tcp_state* _state;

};

class tcp_state
{
public:
    virtual void transmit(tcp_connection* tcp_con, tcp_octet_stream* tcp_oct) {}
    virtual void active_open(tcp_connection* tcp_con) {}
    virtual void passive_open(tcp_connection* tcp_con) {}
    virtual void close(tcp_connection* tcp_con) {}
    virtual void send(tcp_connection* tcp_con) {}
    virtual void acknowledge(tcp_connection* tcp_con) {}
    virtual void synchronize(tcp_connection* tcp_con) {}

protected:
    void change_state(tcp_connection* tcp_con, tcp_state* tcp_st) { tcp_con->change_state(tcp_st); }
};

class tcp_established : public tcp_state {
public:
    static tcp_state* instance() { static tcp_established s; return &s; }
    virtual void transmit(tcp_connection* tcp_con, tcp_octet_stream* tcp_oct) override { tcp_con->process_octet(tcp_oct); }
    virtual void close(tcp_connection* tcp_con) override { change_state(tcp_con, tcp_listen::instance()); }
};

class tcp_listen : public tcp_state {
public:
    static tcp_state* instance() { static tcp_listen s; return &s; }
    virtual void send(tcp_connection* tcp_con) override { change_state(tcp_con, tcp_established::instance()); }
};

class tcp_closed : public tcp_state {
public:
    static tcp_state* instance() { static tcp_closed s; return &s; }
    virtual void active_open(tcp_connection* tcp_con) override { change_state(tcp_con, tcp_established::instance()); }
    virtual void passive_open(tcp_connection* tcp_con) override { change_state(tcp_con, tcp_listen::instance()); }
};

int main()
{
    return 0;
}
