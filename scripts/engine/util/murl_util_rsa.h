// Copyright 2012 Spraylight GmbH

#ifndef __MURL_UTIL_RSA_H__
#define __MURL_UTIL_RSA_H__

#include "murl_string.h"
#include "murl_data.h"

namespace Murl
{
    namespace Util
    {
        /**
         * @ingroup MurlUtilClasses
         * @brief The rsa crypto class.
         */
        class Rsa
        {
        public:
            /**
             * @brief Encrypt data using a public key string.
             * @param message The data object to encrypt.
             * @param publicKey The public key.
             * @return The encrypted data object.
             */
            static Data Encrypt(const ConstData& message, const String& publicKey);
            /**
             * @brief Encrypt data using a public key data object.
             * @param message The data object to encrypt.
             * @param publicKey The public key.
             * @return The encrypted data object.
             */
            static Data Encrypt(const ConstData& message, const ConstData& publicKey);
            
            /**
             * @brief Decrypt data using a private key string.
             * @param cypher The data object to decrypt.
             * @param privateKey The private key.
             * @return The decrypted data object.
             */
            static Data Decrypt(const ConstData& cypher, const String& privateKey);
            /**
             * @brief Decrypt data using a private key data object.
             * @param cypher The data object to decrypt.
             * @param privateKey The private key.
             * @return The decrypted data object.
             */
            static Data Decrypt(const ConstData& cypher, const ConstData& privateKey);
            
            /**
             * @brief Sign data using a private key string.
             * @param message The data object to sign.
             * @param privateKey The private key.
             * @return The signed data object.
             */
            static Data Sign(const ConstData& message, const String& privateKey);
            /**
             * @brief Sign data using a private key data object.
             * @param message The data object to sign.
             * @param privateKey The private key.
             * @return The signed data object.
             */
            static Data Sign(const ConstData& message, const ConstData& privateKey);
            
            /**
             * @brief Verify data using a public key string.
             * @param cypher The data object to verify.
             * @param publicKey The public key.
             * @return The verified data object.
             */
            static Data Verify(const ConstData& cypher, const String& publicKey);
            /**
             * @brief Verify data using a public key data object.
             * @param cypher The data object to verify.
             * @param publicKey The public key.
             * @return The verified data object.
             */
            static Data Verify(const ConstData& cypher, const ConstData& publicKey);
        };
    }
}

#endif // __MURL_UTIL_RSA_H__
