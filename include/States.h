//
// Create by ahmad on 2/13/21.
//

#ifndef RAWSOCKET_STATES_H
#define RAWSOCKET_STATES_H

/**
 * @brief current state of server state machine
 */
enum class ServerState {
    /// server waiting for connections
    server_idle,
    /// server received the handshake message from client and replied to it
    server_handshake,
    /// server's reply acknowledged by client and comm. started
    server_ready 
};

/**
 * @brief current state of client state machine
 */
enum class ClientState {
    /// client hasn't sent any message to server
    client_idle,
    /// client has sent tcp SYN message on raw socket
    client_tcp_raw_handshake,
    /// client is using linux default socket and establishing tcp connection
    client_tcp_dummy_handshake,
    /// exchange of information between client and server
    client_info_handshake1,
    /// exchange of information between client and server2 (may be removed in future)
    client_info_handshake2,
    /// client is ready to send or receive data
    client_ready
};

/**
 * @brief current state of program depending upon if 
 * client or server is running
 * 
 * union will only store only one of the two objects in memory
 * at the same location
 */
union ProgramCurrentState {
    /// current state if client program running
    ClientState client_state;
    /// current state if server program running
    ServerState server_state;
};

#endif //RAWSOCKET_STATES_H