#pragma once
#include "TwoChooseOne/OTExtInterface.h"
#include  "Common/BitVector.h"
#include "Crypto/PRNG.h"
#include "Math/ZpField.h"


namespace osuCrypto
{

    class CopeOtExtSender
    {

    public:
        //CopeOtExtSender();
        //~CopeOtExtSender();



        std::array<PRNG, gOtExtBaseOtCount> mGens;
        BitVector mBaseChoiceBits;

        bool hasBaseOts() const
        {
            return mBaseChoiceBits.size() > 0;
        }

        std::unique_ptr<CopeOtExtSender> split();

        void setBaseOts(
            ArrayView<block> baseRecvOts,
            const BitVector& choices);


        void send(
            ArrayView<ZpNumber> messages,
            Channel& chl);

    };

}
