//
// Create by ahmad on 2/13/21.
//

#ifndef RAWSOCKET_PROGRAMSTATE_H
#define RAWSOCKET_PROGRAMSTATE_H

/**
 * @brief socket type for this program
 */
enum class socket_mode_t {
    /// tcp raw socket based transport
    mode_raw_tcp = 0,
    /// udp raw socket based transport
    mode_raw_udp,
    /// icmp raw socket based transport
    mode_raw_icmp,
    /// linux default tcp socket based transport
    mode_tcp,
    /// linux default udp socket based transport
    mode_udp,
    /// linux default icmp socket based transport
    mode_icmp,
    /// socket not defined
    mode_none };

/**
 * @brief program mode i.e. if client or server is running
 */
enum class program_mode_t {
    /// at start when program mode is unknown
    mode_unset = 0,
    /// program running in client mode
    mode_client,
    /// program running in server mode
    mode_server };

/**
 * @brief current state of server state machine
 */
enum class server_state_t {
    /// server waiting for connections
    server_idle = 0,
    /// server received the handshake message from client and replied to it
    server_handshake,
    /// server's reply acknowledged by client and comm. started
    server_ready };

/**
 * @brief current state of client state machine
 */
enum class client_state_t {
    /// client hasn't sent any message to server
    client_idle = 0,
    /// client has sent tcp SYN message on raw socket
    client_tcp_raw_handshake,
    /// client is using linux default socket and establishing tcp connection
    client_tcp_dummy_handshake,
    /// exchange of information between client and server
    client_info_handshake1,
    /// exchange of information between client and server2 (may be removed in future)
    client_info_handshake2,
    /// client is ready to send or receive data
    client_ready };

/**
 * @brief current state of program depending upon if 
 * client or server is running
 * 
 * union will only store only one of the two objects in memory
 * at the same location
 */
union program_state_t {
    /// current state if client program running
    client_state_t client_state;
    /// current state if server program running
    server_state_t server_state;
};

#endif //RAWSOCKET_PROGRAMSTATE_H