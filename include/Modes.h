//
// Create by ahmad on 2/13/21.
//

#ifndef RAWSOCKET_MODES_H
#define RAWSOCKET_MODES_H

/**
 * @brief socket type for this program
 */
enum class SocketMode {
    /// socket not defined
    mode_none,
    /// tcp raw socket based transport
    mode_raw_tcp,
    /// udp raw socket based transport
    mode_raw_udp,
    /// icmp raw socket based transport
    mode_raw_icmp,
    /// linux default tcp socket based transport
    mode_tcp,
    /// linux default udp socket based transport
    mode_udp,
    /// linux default icmp socket based transport
    mode_icmp
};

/**
 * @brief program mode i.e. if client or server is running
 */
enum class ProgramMode {
    /// at start when program mode is unknown
    mode_unset,
    /// program running in client mode
    mode_client,
    /// program running in server mode
    mode_server 
};


#endif //RAWSOCKET_MODES_H
