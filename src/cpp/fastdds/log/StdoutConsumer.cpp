// Copyright 2019, 2020 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fastdds/dds/log/StdoutConsumer.hpp>
#include <iostream>
#include <iomanip>

namespace eprosima {
namespace fastdds {
namespace dds {

void StdoutConsumer::Consume(
        const Log::Entry& entry)
{
    print_header(entry);
    print_message(&std::cout, entry, true);
    print_context(entry);
    print_new_line(&std::cout, true);
}

void StdoutConsumer::print_header(
        const Log::Entry& entry) const
{
    print_timestamp(&std::cout, entry, true);
    LogConsumer::print_header(&std::cout, entry, true);
}

void StdoutConsumer::print_context(
        const Log::Entry& entry) const
{
    LogConsumer::print_context(&std::cout, entry, true);
}

} // Namespace dds
} // Namespace fastdds
} // Namespace eprosima
