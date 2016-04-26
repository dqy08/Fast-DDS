#include <fastrtps/rtps/network/NetworkFactory.h>
#include <utility>
using namespace std;

namespace eprosima{
namespace fastrtps{
namespace rtps{

vector<SenderResource> NetworkFactory::BuildSenderResources(Locator_t local)
{
   vector<SenderResource> newSenderResources; 

   for(auto& transport : mRegisteredTransports)
   {
      if ( transport->IsLocatorSupported(local) &&
          !transport->IsOutputChannelOpen(local) )
      {
         SenderResource newSenderResource(*transport, local);
         newSenderResources.push_back(move(newSenderResource));
      }
   }
   return newSenderResources;
}

vector<SenderResource> NetworkFactory::BuildSenderResourcesForRemoteLocator(Locator_t remote)
{
   vector<SenderResource> newSenderResources; 

   for(auto& transport : mRegisteredTransports)
   {
      Locator_t local = transport->RemoteToMainLocal(remote);
      if ( transport->IsLocatorSupported(local) &&
          !transport->IsOutputChannelOpen(local) )
      {
         SenderResource newSenderResource(*transport, local);
         newSenderResources.push_back(move(newSenderResource));
      }
   }
   return newSenderResources;
}

vector<ReceiverResource> NetworkFactory::BuildReceiverResources(Locator_t local)
{
   vector<ReceiverResource> newReceiverResources; 

   for(auto& transport : mRegisteredTransports)
   {
      if ( transport->IsLocatorSupported(local) &&
          !transport->IsInputChannelOpen(local) )
      {
         ReceiverResource newReceiverResource(*transport, local);
         newReceiverResources.push_back(move(newReceiverResource));
      }
   }
   return newReceiverResources;
}

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima
