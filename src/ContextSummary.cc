//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ContextSummary.h"

int ContextSummary::getHopLimit() const
{
    return hopLimit;
}

int ContextSummary::getId() const
{
    return id;
}

int ContextSummary::getNumContextItems() const
{
    return context.size();
}

simtime_t ContextSummary::getTimestamp() const
{
    return timestamp;
}

void ContextSummary::setHopLimit(int hopLimit)
{
    this->hopLimit = hopLimit;
}

void ContextSummary::decrementHopLimit()
{
    this->hopLimit--;
}

void ContextSummary::setId(int id)
{
    this->id = id;
}

void ContextSummary::setTimestamp(simtime_t timestamp)
{
    this->timestamp = timestamp;
}

void ContextSummary::setContextItem(int label, int value) {
    context[label] = value;
}

int ContextSummary::getWireSize() const
{
    int size = 0;
    size += 40; // 40 bytes for bloomier filter parameters
    size += 5 * getNumContextItems() * 1.20; // 5 bytes per table entry * number of entries (with 20% more entries than context items)
    return size;
}

ContextMap ContextSummary::getContextMap() {
    return context;
}

