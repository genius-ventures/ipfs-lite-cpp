
#include "data_transfer/message.hpp"

namespace sgns::data_transfer {

  DataTransferMessage createRequest(std::string base_cid,
                                    bool is_pull,
                                    std::vector<uint8_t> selector,
                                    std::vector<uint8_t> voucher,
                                    std::string voucher_type,
                                    TransferId transfer_id) {
    return DataTransferMessage{
        /*.is_request = */true,
        /*.request = */DataTransferRequest{/*.base_cid = */std::move(base_cid),
                                       /*.is_cancel = */false,
                                       /*.pid = */{},
                                       /*.is_part = */false,
                                       /*.is_pull = */is_pull,
                                       /*.selector = */std::move(selector),
                                       /*.voucher = */std::move(voucher),
                                       /*.voucher_type = */std::move(voucher_type),
                                       /*.transfer_id = */transfer_id},
        /*.response = boost::none};*/
        DataTransferResponse{}};
        
  }

  DataTransferMessage createResponse(bool is_accepted, TransferId transfer_id) {
    return DataTransferMessage{
        /*.is_request = */false,
        /*.request = boost::none,*/
        DataTransferRequest{},
        /*.response = */DataTransferResponse{/*.is_accepted = */is_accepted,
                                         /*.transfer_id = */transfer_id}};
  }

}  // namespace sgns::data_transfer
