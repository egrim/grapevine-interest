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
    return numContextItems;
}

simtime_t ContextSummary::getTimestamp() const
{
    return timestamp;
}

void ContextSummary::setHopLimit(int hopLimit)
{
    this->hopLimit = hopLimit;
}

void ContextSummary::setId(int id)
{
    this->id = id;
}

void ContextSummary::setNumContextItems(int numContextItems)
{
    this->numContextItems = numContextItems;
}

void ContextSummary::setTimestamp(simtime_t timestamp)
{
    this->timestamp = timestamp;
}

