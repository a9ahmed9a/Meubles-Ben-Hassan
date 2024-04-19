#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to generate HTML content
string generateHTML(const string& imageName, const string& productName, const string& productPrice, const string& productDescription) {
    string htmlContent = R"(
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="author" content="Ichhari Media">
  <link rel="shortcut icon" href="favicon.png?v2">

  <meta name="description" content="" />

	<!-- Bootstrap CSS -->
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" rel="stylesheet">
	<link href="css/tiny-slider.css" rel="stylesheet">
	<link href="css/style.css?v=1.4" rel="stylesheet">
	<title>)" + productName + R"( | Ichhari-Ecom</title>
</head>
<body>
    <!-- Start Header/Navigation -->
    <nav class="custom-navbar navbar navbar navbar-expand-md navbar-dark bg-dark" arial-label="Furni navigation bar">
        <div class="container">
            <a class="navbar-brand" href="index.html">IKKO cosmetics<span>.</span></a>

            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarsFurni" aria-controls="navbarsFurni" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarsFurni">
                <ul class="custom-navbar-nav navbar-nav ms-auto mb-2 mb-md-0">
                    <li class="nav-item">
                        <a class="nav-link" href="index.html">Home</a>
                    </li>
                    <li><a class="nav-link" href="shop.html">Shop</a></li>
                    <li><a class="nav-link" href="contact.html">Contact us</a></li>
                </ul>
            </div>
        </div> 
    </nav>
    <!-- End Header/Navigation -->

	<!-- single product -->
	<div class="single-product mt-5 ">
		<div class="container">
			<div class="row align-items-center">
				<div class="col-md-5">
					<div class="single-product-img">
						<img src="images/)" + imageName + R"(" alt="" class="img-fluid">
					</div>
				</div>

				<div class="col-md-7 mt-4">
					<div class="single-product-content">
						<h3>)" + productName + R"(</h3>
						<p class="single-product-pricing"><span>)" + productPrice + R"(</span></p>
						<p>)" + productDescription + R"(</p>
						<div class="single-product-form">
							<form action="command.php" methode="post" class="ms-3">
                                <div class="row">
                                    <input type="text" id="Prodname" hidden value=")" + productName + R"( class="w-100">
                                    <div class="col-md-5 col-11">
                                        <label for="name"><p class="m-1">Entrer Votre Nom : </p></label>
                                        <br>
                                        <input type="text" id="name" placeholder="nom Complet" class="w-100">
                                    </div>
                                    <div class="col-md-5 col-11">
                                        <label for="tele"><p class="m-1">Entrer Votre Telephone : </p></label>
                                        <br>
                                        <input type="text" placeholder="Telephone" id="tele" class="w-100">
                                    </div>
                                    <div class="col-md-5 col-11">
                                        <label for="qte"><p class="m-1">Entrer la quantite : </p></label>
                                        <br>
                                        <input type="number" id="qte" placeholder="quantite" class="w-100">
                                    </div>
                                    <div class="col-md-5 col-11">
                                        <label for="adrss"><p class="m-1">Entrer Votre adresse : </p></label>
                                        <br>
                                        <input type="text" placeholder="Adresse" id="adrss" class="w-100">
                                    </div>     
                                    <br>
                                    <div class="col-md-2 col-11">
                                        <input type="submit" value="Commender" class="cart-btn ">
                                    </div>                               
                                </div>
                                
							</form>
							
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
	<!-- end single product -->

	<!-- more products -->
	<div class="more-products mt-5">
		<div class="container">
			<div class="row">
				<div class="col-lg-8 offset-lg-2 text-center">
					<div class="section-title mb-1">	
						<h3><span class="second-color-text">Related</span> Products</h3>
						<p>You May Also Like</p>
					</div>
				</div>
			</div>

			<div class="product-section">
                <div class="container">
                    <div class="row">
                        <!-- Start Column 2 -->
                        <div class="col-12 col-md-4 col-lg-4 mb-5 mb-md-0">
                            <a class="product-item" href="SingleProduct.html">
                                <img src="images/product-1.png" class="img-fluid product-thumbnail">
                                <h3 class="product-title">Nordic Chair</h3>
                                <strong class="product-price">$50.00</strong>
    
                                <span class="icon-cross">
                                    <img src="images/cross.svg" class="img-fluid">
                                </span>
                            </a>
                        </div> 
                        <!-- End Column 2 -->
    
                        <!-- Start Column 3 -->
                        <div class="col-12 col-md-4 col-lg-4 mb-5 mb-md-0">
                            <a class="product-item" href="cart.html">
                                <img src="images/product-2.png" class="img-fluid product-thumbnail">
                                <h3 class="product-title">Kruzo Aero Chair</h3>
                                <strong class="product-price">$78.00</strong>
    
                                <span class="icon-cross">
                                    <img src="images/cross.svg" class="img-fluid">
                                </span>
                            </a>
                        </div>
                        <!-- End Column 3 -->
    
                        <!-- Start Column 4 -->
                        <div class="col-12 col-md-4 col-lg-4 mb-5 mb-md-0">
                            <a class="product-item" href="cart.html">
                                <img src="images/product-3.png" class="img-fluid product-thumbnail">
                                <h3 class="product-title">Ergonomic Chair</h3>
                                <strong class="product-price">$43.00</strong>
    
                                <span class="icon-cross">
                                    <img src="images/cross.svg" class="img-fluid">
                                </span>
                            </a>
                        </div>
                        <!-- End Column 4 -->
    
                    </div>
                </div>
            </div>
		</div>
	</div>
	<!-- end more products -->

	<!-- logo carousel -->
	<div class="logo-carousel-section">
		<div class="container">
			<div class="row">
				<div class="col-lg-12">
					<div class="logo-carousel-inner">
						<div class="single-logo-item">
							<img src="assets/img/company-logos/1.png" alt="">
						</div>
						<div class="single-logo-item">
							<img src="assets/img/company-logos/2.png" alt="">
						</div>
						<div class="single-logo-item">
							<img src="assets/img/company-logos/3.png" alt="">
						</div>
						<div class="single-logo-item">
							<img src="assets/img/company-logos/4.png" alt="">
						</div>
						<div class="single-logo-item">
							<img src="assets/img/company-logos/5.png" alt="">
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
	<!-- end logo carousel -->

    <!-- Start Footer Section -->
    <footer class="footer-section">
        <div class="container relative">

            <div class="sofa-img">
                <img src="images/footerImage.png" alt="Image" class="img-fluid">
            </div>

            <div class="row">
                <div class="col-lg-8">
                    <div class="subscription-form">
                        <ul class="list-unstyled custom-social">
                            <li><a href="#"><span class="fa fa-brands fa-facebook-f"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-twitter"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-instagram"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-linkedin"></span></a></li>
                        </ul>
                    </div>
                </div>
            </div>

            <div class="border-top copyright">
                <div class="row pt-4">
                    <div class="col-lg-6">
                        <p class="mb-2 text-center text-lg-start">Copyright &copy;<script>document.write(new Date().getFullYear());</script>. All Rights Reserved. &mdash; Designed with love by <a href="https://ichhari.com/">Ichhari media</a></p>
                    </div>
                </div>
            </div>

        </div>
    </footer>
    <!-- End Footer Section -->	

    <script src="js/bootstrap.bundle.min.js"></script>
    <script src="js/tiny-slider.js"></script>
    <script src="js/custom.js"></script>
</body>
</html>
)";
    return htmlContent;
}

int main() {
    // Example data
    string imageName = "product-5.png";
    string productName = "Canon EOS 5D Mark IV";
    string productPrice = "$2439.99";
    string productDescription = "Elevate your photography with the Canon EOS 5D Mark IV. This powerful DSLR camera is designed for professionals and enthusiasts alike, delivering exceptional image quality and performance. With a 30.4MP full-frame sensor and advanced DIGIC 6+ image processor, the 5D Mark IV captures stunning detail and clarity in every shot. Its robust construction and weather-sealed design make it ideal for shooting in diverse conditions. Whether you're capturing portraits, landscapes, or events, the EOS 5D Mark IV empowers you to unleash your creativity and achieve your vision.";


    // Generate HTML content
    string htmlContent = generateHTML(imageName, productName, productPrice, productDescription);

    // Write HTML content to file
    ofstream outFile(productName + ".html");
    if (outFile.is_open()) {
        outFile << htmlContent;
        outFile.close();
        cout << "HTML file generated successfully!" << endl;
    } else {
        cerr << "Unable to create HTML file." << endl;
    }

    return 0;
}
