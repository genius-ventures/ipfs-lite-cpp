#ifndef CPP_IPFS_LITE_GRAPHSYNC_REQUEST_BUILDER_HPP
#define CPP_IPFS_LITE_GRAPHSYNC_REQUEST_BUILDER_HPP

#include "message_builder.hpp"

namespace sgns::ipfs_lite::ipfs::graphsync {

  /// Collects request entries and serializes them to wire protocol
  class RequestBuilder : public MessageBuilder {
   public:
    /// Adds request field to outgoing message
    /// \param request_id id of new or cancelled request
    /// \param root_cid root CID
    /// \param selector IPLD selector serialized to bytes
    /// \param extensions - extensions data
    void addRequest(RequestId request_id,
                    const CID &root_cid,
                    gsl::span<const uint8_t> selector,
                    const std::vector<Extension> &extensions);

    /// Adds request to message which cancels the request sent earlier
    void addCancelRequest(RequestId request_id);

    /// Adds "complete request list" flag to message
    void setCompleteRequestList();
  };

}  // namespace sgns::ipfs_lite::ipfs::graphsync

#endif  // CPP_IPFS_LITE_GRAPHSYNC_REQUEST_BUILDER_HPP
