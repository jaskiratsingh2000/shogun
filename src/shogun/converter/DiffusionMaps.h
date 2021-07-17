/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Sergey Lisitsyn, Heiko Strathmann, Evan Shelhamer, Bjoern Esser
 */

#ifndef DIFFUSIONMAPS_H_
#define DIFFUSIONMAPS_H_
#include <shogun/lib/config.h>
#include <shogun/converter/EmbeddingConverter.h>
#include <shogun/features/Features.h>
#include <shogun/kernel/Kernel.h>

namespace shogun
{

class Features;
class Kernel;

/** @brief class DiffusionMaps used to preprocess given data
 * using Diffusion Maps dimensionality
 * reduction technique as described in
 *
 * Coifman, R., & Lafon, S. (2006).
 * Diffusion maps.
 * Applied and Computational Harmonic Analysis, 21(1), 5-30. Elsevier.
 * Retrieved from http://linkinghub.elsevier.com/retrieve/pii/S1063520306000546
 *
 * Uses implementation from the Tapkee library.
 *
 * To use this converter with static interfaces please refer it by
 * sg('create_converter','diffusion_maps',t,width);
 *
 */
class DiffusionMaps: public EmbeddingConverter
{
public:

	/** constructor */
	DiffusionMaps();

	/** destructor */
	~DiffusionMaps() override;

	/** apply preprocessor to features
	 * @param features
	 */
	std::shared_ptr<Features> transform(std::shared_ptr<Features> features, bool inplace = true) override;

	/** embed distance
	 * @param distance to use for embedding
	 * @return embedding simple features
	 */
	virtual std::shared_ptr<DenseFeatures<float64_t>> embed_distance(std::shared_ptr<Distance> distance);

	/** setter for t parameter
	 * @param t t value
	 */
	void set_t(int32_t t);

	/** getter for t parameter
	 * @return t value
	 */
	int32_t get_t() const;

	/** setter for width parameter
	 * @param width width value
	 */
	void set_width(float64_t width);

	/** getter for width parameter
	 * @return width value
	 */
	float64_t get_width() const;

	/** get name */
	const char* get_name() const override;

protected:

	/** default init */
	void init();

protected:

	/** number of steps */
	int32_t m_t;

	/** gaussian kernel width */
	float64_t m_width;
	
	#ifndef SWIG
public:
	static constexpr std::string_view kT = "t";
	static constexpr std::string_view kWidth = "width";

};
}

#endif /* DIFFUSIONMAPS_H_ */
